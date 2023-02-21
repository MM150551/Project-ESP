import os
import cv2
import numpy as np
from PIL import Image

BaseDir = os.path.dirname(os.path.abspath(__file__))
TrainingDataDir = os.path.join(BaseDir,"Training_data")


HaarCascadePath = os.path.join(BaseDir,'HaarCascadeXML\\haarcascade_frontalface_alt2.xml')
FaceCascade = cv2.CascadeClassifier(HaarCascadePath)

recognizer = cv2.face.LBPHFaceRecognizer_create()

tol = 20 #tolerance value for the roi (region of interest)
id_ = 0
training_array = []
label_num_array = []
labels_list = []
previous_label = "batee5"
for root, dirs, files in os.walk(TrainingDataDir):
    for file in files:
        if file.endswith('.jpg') or file.endswith('.png'):
            
            path = os.path.join(root, file)

            label = os.path.basename(os.path.dirname(path)).lower()
            pilImage= Image.open(path).convert("L")
            imageArray = np.array(pilImage,"uint8")
            face = FaceCascade.detectMultiScale(imageArray,1.1,4)
            if not label == previous_label:
                id_ = id_+1
                previous_label = label

            for (x,y,w,h) in face:
                roi = imageArray[y-tol:y+h+tol, x-tol:x+w+tol]
                training_array.append(roi)
                label_num_array.append(id_)
                labels_list.append(label)

            #print(imageArray)
            #print(path)
            #print(label)

print(label_num_array,labels_list)
recognizer.train(training_array, np.array(label_num_array))
recognizer.save(os.path.join(BaseDir,'TrainedDataFile\\trained_data.yml'))