from __future__ import print_function

def backspace_compare_stack(S: str, T: str) -> bool:
    def ending_string(sequence: str) -> str:
        stack = []
        for char in sequence:
            if char == '#':
                if stack:       # only pop if stack isn't empty
                    stack.pop()
            else:
                stack.append(char)
        return ''.join(stack)

    return ending_string(S) == ending_string(T)

def backspace_compare_constant(S: str, T: str) -> bool:
    s_count, t_count = 0, 0     # running count of '#'
    s_ptr, t_ptr = len(S) - 1, len(T) - 1

    while True:
        # jump to next char that won't be deleted
        while s_ptr >= 0 and (s_count > 0 or S[s_ptr] == '#'):
            s_count += 1 if S[s_ptr] == '#' else -1
            s_ptr -= 1

        # for T too
        while t_ptr >= 0 and (t_count > 0 or T[t_ptr] == '#'):
            t_count += 1 if T[t_ptr] == '#' else -1
            t_ptr -= 1

        # check if they're done
        s_done, t_done = s_ptr == -1, t_ptr == -1
        if s_done & t_done:
            return True

        # only one done or the char is different
        if s_done ^ t_done or S[s_ptr] != T[t_ptr]:
            return False

        # the chars match, so decrement both
        s_ptr -= 1
        t_ptr -= 1

tests = [
    [('ab#c', 'ad#c'), True],
    [('a##c', '#a#c'), True],
    [('ab##', 'c#d#'), True],
    [('a#c', 'b'), False],
    [('###', ''), True],
    [('####a', 'a###b#a'), True]
]

for i, test in enumerate(tests):
    input, output = test
    print('Test ' + str(i + 1) + ', S=' + input[0], ", T=" + input[1])
    stack_res = backspace_compare_stack(*input)
    constant_res = backspace_compare_constant(*input)
    print('Result: stack: ' + str(stack_res) + ', constant: ' + str(constant_res))
    assert(stack_res == constant_res == output)
