def is_balanced(string):
    # the list we will use to represent the parens stack
    braces = []
    # iterate through string, looking for parens characters
    for letter in string:
        # if a new opening brace, push the brace onto the stack
        if letter in "[{(":
            braces.append(letter)
        # if a closing brace, make sure pair is correct
        elif letter in "]})":
            # edge case: closing brace with no opening brace
            if len(braces) == 0:
                return False
            last_char = braces.pop()
            if last_char == "[" and letter != "]":
                return False
            elif last_char == "{" and letter != "}":
                return False
            elif last_char == "(" and letter != ")":
                return False
    if len(braces) > 0:
        return False
    return True

strings = {
            "if(this_is_dumb){quit};": True, 
            "){}[({a})]": False, 
            "{{}": False,
            "(can{you(code}this)mess]": False,
            "(((testing)))": True,
            "(((([[{}]]))))": True,
            "({}[]{(([][]))})": True
        }

for item in strings.keys():
    print("expected result: %s\tactual result: %s\tstring: %s" % (str(strings[item]), str(is_balanced(item)), item))
