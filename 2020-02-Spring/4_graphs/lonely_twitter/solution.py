def lonely(users: dict) -> str:
    # users is a dictionary with K:V of str:set
    if not users: return None

    # create differential
    diff = {}
    for user in users:
        diff[user] = 0
        for followed in users[user]:
            if user not in users[followed]: 
                diff[user] -= 1

    # transform differential data into a list of pairs
    result = [(user, count) for user, count in diff.items()]
    # sort list of pairs by differential, lowest to highest
    result.sort(key=lambda x: x[1])
    return result[0][0]
