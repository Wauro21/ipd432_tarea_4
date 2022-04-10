import csv
import math
from random import randrange
import argparse
# Generates a golden-reference file for testing in Vitis_hls

default_file_name = "goldenreference"
default_length = 1024
max_number = 256

def argParser():
    dsc = "This script generates a goldenreference file of 2 vectors, with 1024 random values from 0-255. The output is a csv file, by default, saved at: vitis_hls/goldenreference.csv"
    parser = argparse.ArgumentParser(description = dsc)
    parser.add_argument("-oP","--OutputPath", help = "Indicates where to save the goldenreference file. By default it's saved to: vitis_hls/")
    parser.add_argument("-nf","--nameFile", help = "Select a name for the outputfile, by default it's: {}".format(default_file_name))
    parser.add_argument("-l", "--Length", help = "The length of the vectors to generate, by default it's 1024")
    args = parser.parse_args()
    if args.OutputPath:
        o_path = str(args.OutputPath)
    else:
        o_path = "../vitis_hls/"

    if args.nameFile:
        name_file = str(args.nameFile)
    else:
        name_file = default_file_name
    if args.Length:
        length = int(args.Length)
    else:
        length = default_length
    return o_path, name_file, length

def main():
    path, name_file, length = argParser()
    # Open file
    file = open(path+"/"+name_file+".csv","w")
    writer = csv.writer(file)
    # Generate "8 bit" values, in reality they are just integers.
    for i in range(length):
        A = randrange(max_number)
        B = randrange(max_number)
        row = [A,B]
        writer.writerow(row)
    # Close file
    file.close()

if __name__ == "__main__":
    main()
