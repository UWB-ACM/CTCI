def isValidIP(IP):
    values = IP.split('.')
    if len(values) != 4:
        return False
    for str_val in values:
        # check for leading 0
        if len(str_val) > 1 and str_val[0] == '0':
            return False
        int_val = int(str_val)
        if int_val < 0 or int_val > 255:
            return False
    return True


def main():
    print('IP Address Test Cases:')
    result = isValidIP('192.168.0.1')
    print('Testing 192.168.0.1 (Valid - home <3), Result: ' + str(result))
    assert result
    result = isValidIP('0.0.0.0')
    print('Testing 0.0.0.0 (Valid - standalone zeros are ok), Result: ' + str(result))
    assert result
    result = isValidIP('88.088.088.88')
    print('Testing 88.088.088.88 (Invalid - leading zeros), Result: ' + str(result))
    assert not result
    result = isValidIP('192.168.0')
    print('Testing 192.168.0 (Invalid - less than 4 values), Result: ' + str(result))
    assert not result
    result = isValidIP('355.88.68.1')
    print('Testing 355.0.168.0 (Invalid - value greater than 255), Result: ' + str(result))
    assert not result


if __name__ == '__main__':
    main()
