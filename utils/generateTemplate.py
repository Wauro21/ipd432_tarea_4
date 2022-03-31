def main():
    inst_template = "module_template.txt"
    new_template = "corrected_template.txt"
    file = open(inst_template,"r")
    new_file = open(new_template,"a")
    a_counter = 0
    b_counter = 0
    a_val = "(A[{}])"
    b_val = "(B[{}])"
    for line in file:
        temp = line.strip()
        search_a = '(A_'+str(a_counter)+')'
        search_b = "(B_"+str(b_counter)+")"
        if(search_a in temp):
            new_val = a_val.format(a_counter)
            result = temp.replace(search_a,new_val)
            a_counter +=1
        elif(search_b in line):
            new_val = b_val.format(b_counter)
            result = temp.replace(search_b,new_val)
            b_counter +=1
        else:
            result = temp
        new_file.write(result+"\n")
    file.close()
    new_file.close()
    print("Template generado")
if __name__ == "__main__":
    main()
