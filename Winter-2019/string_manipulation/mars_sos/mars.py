def marsExploration(s):
    sos = "SOS"
    count = 0
    for idx,val in enumerate(s):
        if s[idx] != sos[idx % 3]: 
            count += 1
    return count

def main():
    strings = ['SOSSOSSOS', 'SOSSPSSQSSRS', 'SOSTOT', 'FUNHATSOL']
    for s in strings:
        print(s + ": " + str(marsExploration(s)))
    return

main()
