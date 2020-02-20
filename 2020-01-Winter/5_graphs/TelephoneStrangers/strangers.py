def find_strangers(call_records):
    strangers = []
    for num in call_records:
        for other_num in call_records:
            # edge case since we're iterating through keys twice
            if num == other_num: continue
            if other_num not in call_records[num]:
                # no edge exists between the vertices
                pair = tuple(sorted([num, other_num]))
                if pair not in strangers: strangers.append(pair)
    return strangers

def tests():
    t1 = { '206': [], '940': ['425'], '425': ['940'] }
    print('Test case 1:', t1)
    r1 = find_strangers(t1)
    print('Test 1 result:', r1)
    assert(len(r1) == 2)
    assert(('206', '425') in r1)
    assert(('206', '940') in r1)
    t2 = { '1': ['2', '3', '4'], '2': ['1', '4'], '3': ['1'], '4': ['1', '2'] }
    print('Test case 2:', t2)
    r2 = find_strangers(t2)
    print('Test 2 result:', r2)
    assert(len(r2) == 2)
    assert(('2', '3') in r2)
    assert(('3', '4') in r2)

if __name__=="__main__":
    tests()
