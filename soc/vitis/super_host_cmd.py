from socket import timeout
from regex import D
import serial
import argparse
import random
import numpy as np

ap = argparse.ArgumentParser()
ap.add_argument('-N', nargs=1, required=True, type=int)
ap.add_argument('-port', nargs=1, required=True)
ap.add_argument('-seed', nargs='?', const=1, type=int, default=random.randint(0, 65535))
opt = ap.parse_args()

with serial.Serial('COM6', 115200, timeout=10) as ser:
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

    print(f'Trial euc_dis #{i:d}: PS = {ps_vec[i]:f}, PL = {pl_vec[i]:f}')

  error = ps_vec - pl_vec
  sum_error = np.sum(np.abs(error))
  print(f'Accum error = {sum_error:f}')



