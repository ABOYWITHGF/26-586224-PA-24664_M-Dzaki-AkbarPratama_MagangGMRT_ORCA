import os, shutil
from ultralytics import YOLO
import cv2



model_path = "yolov8n.pt"
capture = cv2.VideoCapture(0)


    
def detect_objects():
    model = YOLO(model_path)


    if not capture.isOpened():
        print("Kamera gak bisa dibuka")
        exit()

    while True:
        ret, frame = capture.read()
        if not ret:
            print("Gagal membaca frame dari kamera")
            break

        if cv2.waitKey(1) & 0xFF == ord('q'):
            break



        results = model.predict(frame, conf=0.5, save=False, classes=[0, 73, 67])

        for result in results:
            annotated_image = result.plot()
            cv2.imshow("Kamera", annotated_image)

if __name__ == "__main__":
    detect_objects()


capture.release()
cv2.destroyAllWindows()
