from info import *
from botbutttton import *
Astra = telebot.TeleBot(token_bot)
list1 =["time", "date","الوقت","الزمن","الساعة","الساعه","وقت","زمن"]
def replay_fun(m):
    if m.text == "اهلا" :
        Astra.reply_to(m," مرحبا بيك")
    elif m.text.lower() == "myinfo" :
            Astra.reply_to(m,m)
    elif m.text == "سلام" :
        Astra.reply_to(m,"سلام ياكبير")  
    elif m.text.lower() == "astra" :   
          Astra.reply_to(m,"you astra ?", reply_markup=list_btn)
    elif m.text.lower() in list1 : 
        Astra.reply_to(m,dt.datetime.now(pytz.timezone("egypt")))   
    elif m.text.lower() == "start" :
        Astra.reply_to(m,"welcom " + m.from_user.first_name +" : this is Astra bot project \nto use bot you should write one of this words: ", reply_markup=list_btn2) 
    elif m.text.lower() == "ban" :
        bnn= Astra.ban_chat_member (m.chat.id, m.reply_to_message.from_user.id)
        if bnn  :
            Astra.send_message(m.chat.id, " البس بان يازعيم" + "@" + str(m.reply_to_message.from_user.username ))
    #else :
      #  Astra.send_photo(m.chat.id, open("pic/tany.jpg", "rb"))
        #Astra.reply_to(m,"عيد السؤال تاني")   
           
    