def reverseWords(s):
    tokens = s.split()
    tokens.reverse()
    return ' '.join(tokens)

print(reverseWords('I am a student.'))
