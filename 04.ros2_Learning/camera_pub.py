import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2

class CameraPublisher(Node):
    def __init__(self):
        super().__init__("camera_publisher")
        
        self.image_pub = self.create_publisher(Image, "/camera_image", 10)
      
        self.timer = self.create_timer(0.03, self.capture_and_publish)
       
        self.cap = cv2.VideoCapture(0)
        self.cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
        self.cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)
       
        self.bridge = CvBridge()
        self.get_logger().info("摄像头发布节点已启动！")

    def capture_and_publish(self):
       
        ret, frame = self.cap.read()
        if ret:
           
            ros_image = self.bridge.cv2_to_imgmsg(frame, encoding="bgr8")
            self.image_pub.publish(ros_image)
        else:
            self.get_logger().warn("无法读取摄像头画面！")

def main(args=None):
    rclpy.init(args=args) 
    node = CameraPublisher()
    rclpy.spin(node)       
    node.cap.release()     
    node.destroy_node()   
    rclpy.shutdown()      

if __name__ == "__main__":
    main()