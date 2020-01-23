import socket

MSGLEN = 1000;

imgcounter = 2
basename = "image%s.png"

class MySocket:
    """demonstration class only
      - coded for clarity, not efficiency
    """

    def __init__(self, sock=None):
        if sock is None:
            self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        else:
            self.sock = sock

    def connect(self, host, port):
        self.sock.connect((host, port))

    def mysend(self, msg):
        totalsent = 0
        while totalsent < MSGLEN:
            sent = self.sock.send(msg[totalsent:])
            if sent == 0:
                raise RuntimeError("socket connection broken")
            totalsent = totalsent + sent

    def myreceive(self):
        data = self.sock.recv(40960000)
        myfile = open(basename % imgcounter, 'wb')
        myfile.write(data)
        myfile.close()
        return(basename % imgcounter)


thisSocket = MySocket();
thisSocket.connect("127.0.0.1",12345)
thisSocket.myreceive();
