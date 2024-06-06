BIN=complain

EXPECTED=expect.log
OUTPUT=out.log
ERROR=error.log

MSG_DEBUG="I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
MSG_INFO="I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"
MSG_WARNING="I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month."
MSG_ERROR="This is unacceptable! I want to speak to the manager now."
MSG_INVALID="Error: Invalid level\nTry one of these:\n1) DEBUG\n2) INFO\n3) WARNING\n4) ERROR"

echo "DEBUG"
echo -e $MSG_DEBUG > $EXPECTED
./$BIN DEBUG > $OUTPUT
diff $EXPECTED $OUTPUT

echo "INFO"
echo -e $MSG_INFO > $EXPECTED
./$BIN INFO > $OUTPUT
diff $EXPECTED $OUTPUT

echo "WARNING"
echo -e $MSG_WARNING > $EXPECTED
./$BIN WARNING > $OUTPUT
diff $EXPECTED $OUTPUT

echo "ERROR"
echo -e $MSG_ERROR > $EXPECTED
./$BIN ERROR > $OUTPUT
diff $EXPECTED $OUTPUT
