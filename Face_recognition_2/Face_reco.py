import cv2 
import os
import Time_API
import pytz
import datetime as dt

BaseDir = os.path.dirname(os.path.abspath(__file__))
HaarCascadePath = os.path.join(BaseDir,'HaarCascadeXML\\haarcascade_frontalface_alt2.xml')
RecognizerPath = os.path.join(BaseDir,'trainedDataFile\\trained_data.yml')
TrainingDataDir = os.path.join(BaseDir,"Training_data")



LogTextFileDir = os.path.join(os.path.dirname(BaseDir),'data.txt')
#LogData = LogTextFile.readlines()

currentTime = Time_API.timeFromString(Time_API.fullTime)
currentDate = Time_API.dateFromString(Time_API.fullTime)
#print(currentDate + " " + currentTime)

#A function to change last seen time of a specified person
def modifyLastSeenTimeTXT(fileDir,currentTime,currentDate,inputName):
    file = open(fileDir,'r')
    Data = file.readlines()
    
    modifiedTXT = []
    formattedCurrentTime = currentDate + " " + currentTime
    for line in Data:
        modifiedTXT.append(line.strip())
    updatedData = Data
    file = open(fileDir,'w')
    try:
        index = modifiedTXT.index(inputName)
    except:
        updatedData.append(inputName + '\n')
        updatedData.append(formattedCurrentTime + '\n')
        for i in range(len(updatedData)):
            file.write(updatedData[i])
        print("Log file updated successfully")
        print("Added " + inputName + " to the text file")
        return 0

    
    updatedData[index] = inputName + "\n"
    updatedData[index+1] = formattedCurrentTime + "\n"
    #print(Data)
    for i in range(len(updatedData)):
        file.write(updatedData[i])
    print("Log file updated successfully")
    print("time for " + inputName +" has been set to " + formattedCurrentTime)


labels_list = ["batee5"]

for root, dirs, files in os.walk(TrainingDataDir):
    for file in files:
        if file.endswith('.jpg') or file.endswith('.png'):
            
            path = os.path.join(root, file)
            label = os.path.basename(os.path.dirname(path)).lower()
            index = len(labels_list)-1
            #print(index)
            if not label == labels_list[index]:
                labels_list.append(label)
#print(labels_list)

recognizer = cv2.face.LBPHFaceRecognizer_create()
frontalFaceCascade = cv2.CascadeClassifier(HaarCascadePath)
#profileFaceCascade = cv2.CascadeClassifier('haarcascade_profileface.xml')
#img = cv2.imread('yosry1.jpg',0)

capture = cv2.VideoCapture(0)
cv2.waitKey(0)
tol = 5

recognizer.read(RecognizerPath)

while capture.isOpened():
    ret, img = capture.read()
    gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    frontalFaces = frontalFaceCascade.detectMultiScale(gray,1.1,4)
    #profileFaces = profileFaceCascade.detectMultiScale(gray,1.1,4)


    for (x,y,w,h) in frontalFaces:
        if w > 100 or h > 100:
            roi_gray = gray[y-tol:y+h+tol, x-tol:x+w+tol]
            try:
                id_ , confidence = recognizer.predict(roi_gray)
            except:
                 print("no face")
            cv2.rectangle(img,(x-tol,y-tol),(x+w+tol,y+h+tol),(0,255,0),3)
            print(confidence)

            if confidence > 60:
                print(labels_list[id_])
                cv2.putText(img, labels_list[id_].upper(), (x-tol,y-tol), cv2.FONT_HERSHEY_PLAIN,1,(255,255,255),1,cv2.LINE_AA)
            if cv2.waitKey(1) == ord('e'):
                if confidence > 60 and confidence < 70:
                    modifyLastSeenTimeTXT(LogTextFileDir,currentTime,currentDate,labels_list[id_])
        
    print(currentTime)
            


    #for (x,y,w,h) in profileFaces:
        #if w > 100 or h > 100:
	        #cv2.rectangle(img,(x,y),(x+w,y+h),(255,0,0),3)

    cv2.imshow("image", img)
    if cv2.waitKey(1) == ord('q'):
            break 

capture.release()
cv2.destroyAllWindows()