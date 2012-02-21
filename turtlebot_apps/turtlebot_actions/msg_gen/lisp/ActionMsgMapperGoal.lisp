; Auto-generated. Do not edit!


(cl:in-package turtlebot_actions-msg)


;//! \htmlinclude ActionMsgMapperGoal.msg.html

(cl:defclass <ActionMsgMapperGoal> (roslisp-msg-protocol:ros-message)
  ((input_topic
    :reader input_topic
    :initarg :input_topic
    :type cl:string
    :initform "")
   (output_topic
    :reader output_topic
    :initarg :output_topic
    :type cl:string
    :initform "")
   (input_type
    :reader input_type
    :initarg :input_type
    :type cl:string
    :initform "")
   (output_type
    :reader output_type
    :initarg :output_type
    :type cl:string
    :initform "")
   (input_list
    :reader input_list
    :initarg :input_list
    :type (cl:vector cl:string)
   :initform (cl:make-array 0 :element-type 'cl:string :initial-element ""))
   (output_list
    :reader output_list
    :initarg :output_list
    :type (cl:vector cl:string)
   :initform (cl:make-array 0 :element-type 'cl:string :initial-element "")))
)

(cl:defclass ActionMsgMapperGoal (<ActionMsgMapperGoal>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ActionMsgMapperGoal>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ActionMsgMapperGoal)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name turtlebot_actions-msg:<ActionMsgMapperGoal> is deprecated: use turtlebot_actions-msg:ActionMsgMapperGoal instead.")))

(cl:ensure-generic-function 'input_topic-val :lambda-list '(m))
(cl:defmethod input_topic-val ((m <ActionMsgMapperGoal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_actions-msg:input_topic-val is deprecated.  Use turtlebot_actions-msg:input_topic instead.")
  (input_topic m))

(cl:ensure-generic-function 'output_topic-val :lambda-list '(m))
(cl:defmethod output_topic-val ((m <ActionMsgMapperGoal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_actions-msg:output_topic-val is deprecated.  Use turtlebot_actions-msg:output_topic instead.")
  (output_topic m))

(cl:ensure-generic-function 'input_type-val :lambda-list '(m))
(cl:defmethod input_type-val ((m <ActionMsgMapperGoal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_actions-msg:input_type-val is deprecated.  Use turtlebot_actions-msg:input_type instead.")
  (input_type m))

(cl:ensure-generic-function 'output_type-val :lambda-list '(m))
(cl:defmethod output_type-val ((m <ActionMsgMapperGoal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_actions-msg:output_type-val is deprecated.  Use turtlebot_actions-msg:output_type instead.")
  (output_type m))

(cl:ensure-generic-function 'input_list-val :lambda-list '(m))
(cl:defmethod input_list-val ((m <ActionMsgMapperGoal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_actions-msg:input_list-val is deprecated.  Use turtlebot_actions-msg:input_list instead.")
  (input_list m))

(cl:ensure-generic-function 'output_list-val :lambda-list '(m))
(cl:defmethod output_list-val ((m <ActionMsgMapperGoal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_actions-msg:output_list-val is deprecated.  Use turtlebot_actions-msg:output_list instead.")
  (output_list m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ActionMsgMapperGoal>) ostream)
  "Serializes a message object of type '<ActionMsgMapperGoal>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'input_topic))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'input_topic))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'output_topic))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'output_topic))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'input_type))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'input_type))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'output_type))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'output_type))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'input_list))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((__ros_str_len (cl:length ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) ele))
   (cl:slot-value msg 'input_list))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'output_list))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((__ros_str_len (cl:length ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) ele))
   (cl:slot-value msg 'output_list))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ActionMsgMapperGoal>) istream)
  "Deserializes a message object of type '<ActionMsgMapperGoal>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'input_topic) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'input_topic) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'output_topic) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'output_topic) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'input_type) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'input_type) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'output_type) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'output_type) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'input_list) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'input_list)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:aref vals i) __ros_str_idx) (cl:code-char (cl:read-byte istream))))))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'output_list) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'output_list)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:aref vals i) __ros_str_idx) (cl:code-char (cl:read-byte istream))))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ActionMsgMapperGoal>)))
  "Returns string type for a message object of type '<ActionMsgMapperGoal>"
  "turtlebot_actions/ActionMsgMapperGoal")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ActionMsgMapperGoal)))
  "Returns string type for a message object of type 'ActionMsgMapperGoal"
  "turtlebot_actions/ActionMsgMapperGoal")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ActionMsgMapperGoal>)))
  "Returns md5sum for a message object of type '<ActionMsgMapperGoal>"
  "9c97ba579bcd822e978741dfc338d44b")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ActionMsgMapperGoal)))
  "Returns md5sum for a message object of type 'ActionMsgMapperGoal"
  "9c97ba579bcd822e978741dfc338d44b")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ActionMsgMapperGoal>)))
  "Returns full string definition for message of type '<ActionMsgMapperGoal>"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%#goal definition~%string    input_topic      ~%string    output_topic      ~%string    input_type      ~%string    output_type      ~%string[]   input_list~%string[]   output_list~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ActionMsgMapperGoal)))
  "Returns full string definition for message of type 'ActionMsgMapperGoal"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%#goal definition~%string    input_topic      ~%string    output_topic      ~%string    input_type      ~%string    output_type      ~%string[]   input_list~%string[]   output_list~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ActionMsgMapperGoal>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'input_topic))
     4 (cl:length (cl:slot-value msg 'output_topic))
     4 (cl:length (cl:slot-value msg 'input_type))
     4 (cl:length (cl:slot-value msg 'output_type))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'input_list) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4 (cl:length ele))))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'output_list) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4 (cl:length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ActionMsgMapperGoal>))
  "Converts a ROS message object to a list"
  (cl:list 'ActionMsgMapperGoal
    (cl:cons ':input_topic (input_topic msg))
    (cl:cons ':output_topic (output_topic msg))
    (cl:cons ':input_type (input_type msg))
    (cl:cons ':output_type (output_type msg))
    (cl:cons ':input_list (input_list msg))
    (cl:cons ':output_list (output_list msg))
))
