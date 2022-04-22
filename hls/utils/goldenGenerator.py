import csv
import math
from random import randrange
from random import uniform
import argparse
# Generates a golden-reference file for testing in Vitis_hls

default_file_name = "goldenreference"
default_length = 1024
MAX_N = 256
MIN_N = 0

def argParser():
    dsc = "This script generates a goldenreference file of 2 vectors, with 1024 random values from 0-255. The output is a csv file, by default, saved at: vitis_hls/goldenreference.csv"
    parser = argparse.ArgumentParser(description = dsc)
    parser.add_argument("-oP","--OutputPath", help = "Indicates where to save the goldenreference file. By default it's saved to: vitis_hls/")
    parser.add_argument("-nf","--nameFile", help = "Select a name for the outputfile, by default it's: {}".format(default_file_name))
    parser.add_argument("-l", "--Length", help = "The length of the vectors to generate, by default it's 1024")
    parser.add_argument("--max", help="Indicates the max number, by default its 255 (8 bit max)")
    parser.add_argument("--min", help="Indicates the max number, by default its 0")
    parser.add_argument("--float", action='store_true',help="Overrides default type for numbers <int> to <float>")
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

    if args.max:
        max_number = int(args.max)
    else:
        max_number = MAX_N

    if args.min:
        min_number = int(args.min)
    else:
        min_number = MIN_N

    if args.float:
        i_type = True # Float
    else:
        i_type = False # Int
    return o_path, name_file, length, max_number, min_number, i_type

def main():
    path, name_file, length, max_number, min_number, type = argParser()
    # Open file
    file = open(path+"/"+name_file+".csv","w")
    writer = csv.writer(file)
    # Generate "8 bit" values, in reality they are just integers.
    for i in range(length):
        if(type):
            A = uniform(min_number, max_number)
            B = uniform(min_number, max_number)
        else:
            A = randrange(min_number,max_number)
            B = randrange(min_number,max_number)
        row = [A,B]
        writer.writerow(row)
    # Close file
    file.close()

if __name__ == "__main__":
    main()
