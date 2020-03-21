#!/bin/bash
RESULT=`./c.exe one two four| grep "Common Chars are"`
if [ "$RESULT" = "Common Chars are [o ]" ] ; then
	echo "test passes"
else
	echo "failure"
fi
