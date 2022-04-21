from regex import D
import serial
import argparse
import random
import numpy as np

ap = argparse.ArgumentParser()
ap.add_argument('-N', nargs=1, required=True, type=int)
ap.add_argument('-port', nargs=1, required=True)
ap.add_argument('-seed', nargs='?', const=1, type=int, default=random.randint(0, 255))
opt = ap.parse_args()

with serial.Serial('COM6', 115200) as ser:
  ps_vec, pl_vec = np.zeros(1024), np.zeros(1024)

  print('Started...')
  print(f'Sending N = {opt.N[0]:d} trials, seed = {opt.seed:d}')
  
  ser.write(chr(opt.N[0]).encode())
  ser.write(chr(opt.seed).encode())

  for i in range(opt.N[0]):
    try:
      buf = ser.readline()[:-2]
    except KeyboardInterrupt:
      exit()

    a_data, b_data = buf.decode('utf-8').split(',')
    ps_vec[i] = float(a_data)
    pl_vec[i] = float(b_data)

    print(f'Trial euc_dis #{i:d}: PS = {ps_vec[i]:f}, PL = {pl_vec[i]:f}')

  error = ps_vec - pl_vec
  sum_error = np.sum(np.abs(error))
  print(f'Accum error = {sum_error:f}')



