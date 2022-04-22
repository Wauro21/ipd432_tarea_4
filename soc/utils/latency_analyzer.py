import csv
import argparse
import numpy as np

def argParser():
    dsc = "This script runs analytics on the output file taken from the logic analyzer, to measure the latency of PS and PL operations in the Zybo"
    parser = argparse.ArgumentParser(description = dsc)
    parser.add_argument("-if","--InputFile", help="File that contains the exported values from the logic analyzer")
    args = parser.parse_args()
    return args.InputFile

def analyze(pin, tiempo,factor_show):
    latency = []
    for i in range(len(pin)):
        if(pin[i]==1):
            temp_lat = (tiempo[i+1] - tiempo[i])*factor_show
            latency.append(temp_lat)
    avg = np.average(latency)
    std = np.std(latency)
    min_val = min(latency)
    max_val = max(latency)
    return avg, std, min_val, max_val

def main():
    tiempo = []
    ps = []
    pl = []
    latency_ps = []
    latency_pl = []
    file_name = argParser()
    try:
        file = open(file_name,"r")
    except:
        print("File could not be found! ")
        exit(1)
    remove_header = True
    for line in file:
        if(remove_header):
            remove_header = False
        else:
            try:
                line = line.strip().split(",")
                t_time, t_ps, t_pl = line
                tiempo.append(float(t_time))
                ps.append(int(t_ps))
                pl.append(int(t_pl))
            except:
                print("More than one pin found, disable unnecesary pins in Logic analyzer!")
                exit(1)

    # Process values
    print("Results for latency")
    ## PS
    avg_ps, std_ps, min_ps, max_ps = analyze(ps, tiempo, 1000000)
    print("PS: AVG Latency {} us | ST.D Latency {} us | Min Latency {} us | Max Latency {} us".format(avg_ps, std_ps, min_ps, max_ps))
    ## PL
    avg_pl, std_pl, min_pl, max_pl = analyze(pl, tiempo, 1000000)
    print("PL: AVG Latency {} us | ST.D Latency {} us | Min Latency {} us | Max Latency {} us".format(avg_pl, std_pl, min_pl, max_pl))



if __name__ == "__main__":
    main()
