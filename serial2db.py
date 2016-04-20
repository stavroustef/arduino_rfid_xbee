_author__ = 'stef'


import MySQLdb
import sys


try:
    db = MySQLdb.connect(
        host = 'localhost',
        user = 'stef',
        passwd = '1234',
        db = 'test'
        )



except Exception as e:
    sys.exit('We cant get into database')
    arduino = serial.Serial("/dev/ttyACM0", 19200)
    quant = 0
while True:
    data = str(arduino.readline())
    print data
    cursor = db.cursor()
    quant = quant + 1
    cursor.execute("UPDATE elements set quantity=%s WHERE name=%s",(quant,data))
    db.commit()