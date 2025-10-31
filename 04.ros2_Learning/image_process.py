import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
import numpy as np

class ImageProcessor(Node):
    def __init__(self):
        super().__init__("image_processor")
     
        self.image_sub = self.create_subscription(
            Image, "/camera_image", self.image_callback, 10
        )
        self.bridge = CvBridge()
        self.get_logger().info("图像处理节点已启动！")

    def image_callback(self, msg):
      
        frame = self.bridge.imgmsg_to_cv2(msg, encoding="bgr8")
        
       
        hsv_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
     
        lower_red = np.array([0, 120, 70])   
        upper_red = np.array([10, 255, 255])
        red_mask = cv2.inRange(hsv_frame, lower_red, upper_red)
       
        red_mask = cv2.dilate(red_mask, np.ones((5,5), np.uint8), iterations=1)
        
      
       
        lower_blue = np.array([100, 30, 30])  
        upper_blue = np.array([255, 100, 100])
        blue_mask = cv2.inRange(frame, lower_blue, upper_blue)
        blue_mask = cv2.dilate(blue_mask, np.ones((5,5), np.uint8), iterations=1)
        
        self.draw_contour(frame, red_mask, (0, 0, 255), "Red")    
        self.draw_contour(frame, blue_mask, (255, 0, 0), "Blue") 
        
        
        cv2.imshow("Color Detection Result", frame)
        cv2.waitKey(1)  

    def draw_contour(self, img, mask, color, label):
       
        contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
        for cnt in contours:
         
            if cv2.contourArea(cnt) > 500:
                x, y, w, h = cv2.boundingRect(cnt)
                cv2.rectangle(img, (x, y), (x+w, y+h), color, 2) 
                cv2.putText(img, label, (x, y-10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, color, 2) 

def main(args=None):
    rclpy.init(args=args)
    node = ImageProcessor()
    rclpy.spin(node)
    cv2.destroyAllWindows()  
    node.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()