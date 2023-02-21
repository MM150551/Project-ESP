def sendByte(name, acceptance = True):
    '''
    Return value:
                None, this function takes 2 arguments and send them via UART protocol to the micro-controller.
    This function takes 2 arguments:
                'name'              that refers to the recognized person.
                'acceptance'        that refers to the action that micro-controller should performe.
    Restrictions:
                Name length MUST be < 16 byte
    if face is verified             acceptance = True && name != 'UNKNOWN'
    if face is not verified         acceptance = False && name = 'UNKNOWN'
    '''
    pass

def getDataFromTextFile(path):
    '''
    Most recent attendance is located at the file's tail.
    The index of it's name is -2
    as the formate of the attendance is as following:
            Name
            Data    Time

    Return value:
                String, this function returns the name of the last attendance.
    This function takes 1 arguments:
                'path'              that refers to the text file used as a database
    Restrictions:
                Name length MUST be < 16 byte
    if face is verified             acceptance = True && name != 'UNKNOWN'
    if face is not verified         acceptance = False && name = 'UNKNOWN'
    '''
    file = open(path, 'r')
    lines = file.readlines()
    if len(lines[-2]) > 16:
        raise OverflowError (
        f'''
        Assigned buffer in receiver is only 16 Byte size, name is {len(lines)} bytes.

        Make sure that data size you want to transmitt is not greater than 16 byte.

        Try reducing data size long or choose a compressed form.
        '''
        )
    else:
        return lines[-2]
