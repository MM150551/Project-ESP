'''
This code is for face verification using the Deepface library.

The code starts by defining a dictionary known_faces, which contains the path to a known face image.
Then, a list unknown_faces is defined, which contains the paths to several unknown face images.

The DeepFace library is then imported, and a loop is used to compare the known face image to each of the unknown face images.
The verify function is used to perform the comparison, and the results are printed to the console.
If the comparison is successful (i.e., the faces match), the result is added to a dictionary results.

Next, the matplotlib library and the PIL library are imported.
The known face image is loaded, and a plot is created to display it.

Then, the unknown face images are loaded and plotted using a loop.
The results from the comparison in the earlier step are used to add a label to each plot indicating whether the face was verified or not, and which known face it matched.

Overall, this code performs face verification on a set of known and unknown faces and displays the results.
'''

import os
os.chdir('C:\\Users\\mina1\\source\\Python_files\\face_reco_data')
known_faces = ['chick', '12.jpg']
unknown_faces = ['1.jpg', '2.jpg', '3.jpg','4.jpg','121212.jpg','6.jpg','7.jpg','8.jpg','9.jpg','10.jpg','11.jpg','66.jpg','leefa.jpg','1212.jpg','111.jpg','222.jpg']

'''
iterate through each known and unknown face to verify them using DeepFace library.

When processing a video stream for face recognition, the loop used for processing unknown faces in the image data can be
replaced with processing the frames of the video stream.
However, to improve performance, it's important to scale the video stream and consider ignoring some frames during processing.
This approach can result in more fast recognition in real-time video streams.
'''

from deepface import DeepFace
results = {}


for unknown_face in unknown_faces: #this loop can be replaced with (video data stream)
    try:
      result = DeepFace.verify(img1_path = known_faces[1], img2_path = unknown_face)
      print(result, '\n\n')
      if (result['verified']):
        results[unknown_face] = f'is {known_faces[0]}'
      else:
        results[unknown_face] = f'is not {known_faces[0]}'
    except:
      results[unknown_face] = f'FILED TO DETECT THE FACE'

      print(f"""

      HANDLED ERROR | in :{unknown_face}
            
            """)


'''show the known image with its label'''
import matplotlib.pyplot as plt
from PIL import Image


#making the shape
fig=plt.figure()
# Load the images
image1 = Image.open(known_faces[1])
plt.imshow(image1)
plt.title(f'The Known image, label = {known_faces[0]}')
plt.show()


'''display the results of the verification'''
from math import ceil
cols = 1
rows = ceil (len(unknown_faces)/cols)

results_keys = list(results.keys())
results_items = list(results.items())

print(results)

fig = plt.figure()
for i in range(0, len(results_keys)):
    img = Image.open(results_keys[i])
    fig.add_subplot(rows, 4, 1+i)
    plt.title(f'{results_keys[i].split("/")[-1]} | {results_items[i]}')
    plt.imshow(img)
plt.show()
