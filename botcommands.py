from info import *
from botbutttton import *
def comnd_ban_fun(m):
    if m.text.lower() == "/ban" :
        #Astra.send_message(m.chat.id, "البس بان " + "@"+ m.reply_to_message.from_user.username )
        bnn= Astra.ban_chat_member (m.chat.id, m.reply_to_message.from_user.id)
        if bnn  :
            Astra.send_message(m.chat.id, " البس بان يازعيم" + "@" + str(m.reply_to_message.from_user.username ))
def comnd_star_fun(m):
    if m.text.lower() == "/start" :
        #Astra.reply_to(m,"welcom: this is Astra bot project ")#, #reply_markup=list_btn)
        Astra.send_message(m.chat.id,"welcom " + m.from_user.first_name +" : this is Astra bot project \nto use bot you should write one of this words: ",reply_markup=list_btn2)