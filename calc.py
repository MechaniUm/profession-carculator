from serial import Serial
import sqlite3 as sql
from time import sleep
from PIL import ImageTk
from PIL import Image as PilImage
from tkinter import *
import tkinter.font
from threading import Thread
import pygame
import json

from properties import *



def insert_newlines_header(string):
    l = len(string)
    s = ""
    w = 0
    idx = 0
    i = 0
    while i < l:
        if string[i] == ' ':
            idx = i
        if w > 20:
            if i == ' ':
                s+='\n'
                w=0
            else:
                if not idx == i:
                    s=s[:(idx - i)]
                s+='\n'
                i=idx
                w=0
        else:
            s+=string[i]
        w+=1
        i+=1
    return s

def insert_newlines(string, w_max=44):
    l = len(string)
    s = ""
    w = 0
    idx = 0
    i = 0
    while i < l:
        if string[i] == ' ':
            idx = i
        if w > w_max:
            if i == ' ':
                s+='\n'
                w=0
            else:
                if not idx == i:
                    s=s[:(idx - i)]
                s+='\n'
                i=idx
                w=0
        else:
            s+=string[i]
        w+=1
        i+=1
    return s

class Application(Frame):

    def set_volume(self, volume):
        #self.sounds['good'].set_volume(volume / 1000)
        #self.sounds['info'].set_volume(volume / 1000)
        for key in self.sounds:
            self.sounds[key].set_volume(volume / 1000)

    def create_widgets(self):
        self.c = Canvas(self, height = 600, width = 1024)
        self.c.pack()
        self.background_img = self.c.create_image(0,0,image=self.background_filename,anchor=NW, tag='main')
        self.profession_img = self.c.create_image(237,299,image=self.images[self.images_numbers['Министр']], tag='main')
        #self.c.create_image(237,299,image=self.images[self.images_numbers['Министр']], tag='prof_img')
        self.info_img = self.c.create_image(0,0,image=self.info_filename, tag='info', anchor=NW)
        self.question_img = self.c.create_image(0,0,image=self.question_filename, tag='question', anchor=NW)
        self.logo_img = self.c.create_image(0,0,image=self.logo_filename, tag='logo', anchor=NW)
        
        #self.profession_name = Label(self, text='', font=self.fonts['h'],bg='white',fg="#29395f")
        #self.about = Label(self, text=insert_newlines(''), bg='white',font=self.fonts['p'], justify='left')
        
        self.profession_name = self.c.create_text(740,200,anchor=S,font='FuturaPT 30', tag='main', fill="#29395f")
        self.about = self.c.create_text(490,270,anchor=NW, font='FuturaPt 18', tag='main')
        
    def forget_labels(self):
        self.profession_name.place_forget()
        self.about.place_forget()

    def place_labels(self):
        self.profession_name.place(x=740,y=210,anchor='s')
        self.about.place(x=490,y=270,anchor='nw')
    
    def show_question(self):
        self.c.tag_raise('question')

    def wake_up(self):
        self.c.tag_raise('info')
        self.sounds['info'].play()

    def go_to_sleep(self):
        #self.forget_labels()
        self.c.tag_raise('logo')
        
    def show_next(self):
        self.stop_sounds();
        conn = sql.connect("/home/pi/Documents/calculator/calculator.db")
        cursor = conn.cursor()
        cursor.execute(next_item_query, {
            "id_p": self.data['p']
        })
        tmp = cursor.fetchone()
        filename = self.images[self.images_numbers[tmp[2]]]
        self.data['p'] = str(int(tmp[3]) + 1)
        if (self.data['p'] == '6'):
            self.data['p'] = '7'
        if (self.data['p'] == '43'):
            self.data['p'] = '44'
        if (self.data['p'] == '51'):
            self.data['p'] = '1'
        self.c.itemconfigure(self.profession_img, image=filename)
        self.c.itemconfigure(self.profession_name, text=insert_newlines_header(tmp[0]))
        self.c.itemconfigure(self.about, text=insert_newlines(tmp[1]))
        self.c.tag_raise('main')
        conn.close()
        sleep(0.5)
    
    def update_gui(self):
        self.sounds['good'].play()
        self.show_question()
        sleep(7)
        conn = sql.connect("/home/pi/Documents/calculator/calculator.db")
        cursor = conn.cursor()
        cursor.execute(query, {
            "id_i": self.data['i'],
            "id_s": self.data['s'],
            "id_q": self.data['q']
        })
        tmp = cursor.fetchone()
        #self.profession_name.configure(text=insert_newlines_header(tmp[0]))
        #self.about.configure(text=insert_newlines(tmp[1]))
        filename = self.images[self.images_numbers[tmp[2]]]
        self.sounds[tmp[2]].play()
        self.data['p'] = str(int(tmp[3]) + 1)
        if (self.data['p'] == '6'):
            self.data['p'] = '7'
        if (self.data['p'] == '43'):
            self.data['p'] = '44'
        if (self.data['p'] == '51'):
            self.data['p'] = '1'
        self.c.itemconfigure(self.profession_img, image=filename)
        self.c.itemconfigure(self.profession_name, text=insert_newlines_header(tmp[0]))
        self.c.itemconfigure(self.about, text=insert_newlines(tmp[1]))
        self.c.tag_raise('main')
        conn.close()
        #self.place_labels()
        
    def loop_serial(self):
        try:
            s = Serial("/dev/ttyACM1", 9600, timeout=1)
        except:
            try:
                s = Serial("/dev/ttyACM0", 9600, timeout=1)
            except:
                try:
                    s = Serial("/dev/ttyUSB0", 9600, timeout=1)
                except:
                    try:
                        s = Serial("/dev/ttyUSB1", 9600, timeout=1)
                    except:
                        return
                    
        while(1):
            try:
                inp = (s.readline())
                msg = str(inp).split("'")[1].split('\n')[0][:-2]
                if (len(msg) == 0):
                    continue
                msg_data = json.loads(msg)
                print(msg_data)
                if (msg_data['event'] == 'button_pressed') and (msg_data['options']['buttonID'] == 1):
                    self.data['i'] = msg_data['options']['i']
                    self.data['s'] = msg_data['options']['s']
                    self.data['q'] = msg_data['options']['t']
                    self.update_gui()
                elif (msg_data['event'] == 'wake_up'):
                    self.wake_up()
                elif (msg_data['event'] == 'sleep'):
                    self.go_to_sleep()
                elif (msg_data['event'] == 'new_object'):
                    self.stop_sounds()
                    self.show_question()
                elif (msg_data['event'] == 'set_volume'):
                    self.set_volume(msg_data['options']['volume'])
                elif ((msg_data['event'] == 'stop_sounds') or (msg_data['event'] == 'stop_info')):
                    self.stop_sounds()
                elif (msg_data['event'] == 'show_next'):
                    self.show_next()
            except:
                pass
    
    def stop_sounds(self):
        #self.sounds['info'].stop()
        #self.sounds['good'].stop()
        for key in self.sounds:
            self.sounds[key].stop()
    
    def __init__(self,master=None):
        super().__init__(master)
        self.master = master
        self.pack()
        pygame.init()
        self.fonts = {'p': tkinter.font.Font(family = 'Futura PT', size = 16), 'h': tkinter.font.Font(family = 'Futura PT', size = 30)}
        self.sounds = {'good': pygame.mixer.Sound("/home/pi/Documents/calculator/Sounds/ok.ogg"), 'info': pygame.mixer.Sound("/home/pi/Documents/calculator/Sounds/info.ogg")}
        self.load_images()
        self.create_widgets()
        self.serial_thread = Thread(target = self.loop_serial)
        self.data = {'i': 0, 'q': 0, 's': 0}
        self.set_volume(100)
        self.serial_thread.start()
     
    def load_images(self):
        self.images = []
        self.images_numbers = {}
        conn = sql.connect("/home/pi/Documents/calculator/calculator.db")
        cursor = conn.cursor()
        image_paths = cursor.execute("SELECT image FROM professions")
        idx = 0
        for path in image_paths:
            tmp_img = ImageTk.PhotoImage(PilImage.open("/home/pi/Documents/calculator/Pictures/" + path[0] + ".png"))
            self.images.append(tmp_img)
            self.images_numbers[path[0]] = idx
            #print(path[0])
            self.sounds[path[0]] = pygame.mixer.Sound("/home/pi/Documents/calculator/Sounds/" + path[0] + ".ogg")
            idx+=1
        conn.close()
        self.background_filename = ImageTk.PhotoImage(PilImage.open("/home/pi/Documents/calculator/Pictures/background.png"))
        self.logo_filename = ImageTk.PhotoImage(PilImage.open("/home/pi/Documents/calculator/Pictures/logo.png"))
        self.info_filename = ImageTk.PhotoImage(PilImage.open("/home/pi/Documents/calculator/Pictures/info.png"))
        self.question_filename = ImageTk.PhotoImage(PilImage.open("/home/pi/Documents/calculator/Pictures/question.png"))

    


if __name__ == "__main__":
    root = Tk()
    root.attributes("-fullscreen", True) 
    root.title("professions calculator")
    app = Application(master=root)
    app.mainloop()
