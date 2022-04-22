from socket import timeout
from regex import D
import serial
import argparse
import random
import numpy as np

tolerance_difference = 1.0 #maximun difference between PL value and PS value
direct_errors = []


dsc= "Script to initiate the trial operations in the SoC"
ap = argparse.ArgumentParser(description=dsc)
ap.add_argument('-N' , help = "Number of trials", nargs=1, required=True, type=int)
ap.add_argument('-port', nargs=1, required=True)
ap.add_argument('-seed', nargs='?', const=1, type=int, default=random.randint(0, 65535))
opt = ap.parse_args()

print(opt.port)

with serial.Serial(opt.port[0], 115200, timeout=10) as ser:
  ps_vec, pl_vec = np.zeros(1024), np.zeros(1024)

  print('Started...')
  print(f'Sending N = {opt.N[0]:d} trials, seed = {opt.seed:d}')

  ser.write(opt.N[0].to_bytes(2, 'big'))
  ser.write(opt.seed.to_bytes(2, 'big'))

  for i in range(opt.N[0]):
    try:
      buf = ser.readline()[:-2]

      a_data, b_data = buf.decode('utf-8').split(',')
      ps_vec[i] = float(a_data)
      pl_vec[i] = float(b_data)

    except:
      print('Timeout reached')
      exit()

    # Evaluation
    direct_diff = abs(ps_vec[i]-pl_vec[i])
    relative_diff = direct_diff/ps_vec[i]
    direct_errors.append(direct_diff)
    if(direct_diff > tolerance_difference):
        t_result = "FAIL!"
    else:
        t_result = "PASS!"
    print(f'Trial euc_dis #{i:d}: PS = {ps_vec[i]:f}, PL = {pl_vec[i]:f}, Direct Difference  = {direct_diff:f}, Relative Difference = {relative_diff:f}, {t_result}')

  error = ps_vec - pl_vec
  sum_error = np.sum(np.abs(error))
  avg_direc = np.average(direct_errors)
  std_direc = np.std(direct_errors)
  max_error = max(direct_errors)
  min_error = min(direct_errors)
  print(f'Accumulated error = {sum_error:f} | AVG Direct Error = {avg_direc:f} | ST.D Direct Error = {std_direc:f} | Max Direct Error = {max_error:f} | Min Direct Error = {min_error:f}')
