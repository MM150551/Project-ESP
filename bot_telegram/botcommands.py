from info import *
from botbutttton import *

def command_fun(m):
    if m.text.lower() == "/ban" :
        bnn= Astra.ban_chat_member (m.chat.id, m.reply_to_message.from_user.id)
        if bnn  :
            Astra.send_message(m.chat.id, " GET OUT " + "@" + str(m.reply_to_message.from_user.first_name ))
    elif m.text.lower() == "/start" :
        Astra.send_message(m.chat.id,"welcom " + m.from_user.first_name +" : this is Astra bot project \nto use bot you should write one of this words: ",reply_markup=list_btn2)

    elif m.text.lower() == "/my_info" :
        Astra.reply_to(m,m)  
              

        