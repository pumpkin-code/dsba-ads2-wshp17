# -*- coding: utf-8 -*-
"""
Testing Regular expressions.

https://docs.python.org/3/howto/regex.html
"""

import re


def test1():
    print("Test1")
    
    e1 = re.compile("ab*")
    print(e1)
    
    r1 = e1.match("a")
    print(r1)
        
    r1 = e1.match("ab")
    print(r1)    
    
    r1 = e1.match("abc")
    print(r1)    

    r1 = e1.match("bc")
    print(r1)  

    s1 = "asd123sdf456\nThe phone number is +7-495-772-9590.\nAnother number is +7-916-123-1718."
    e2 = re.compile("[0-9]{3}")
    r2 = e2.search(s1)
    print(r2)
    
    r3 = e2.findall(s1)
    print(r3)


if __name__ == "__main__":
    test1()
    # test2()

    print('Hello world!')
    