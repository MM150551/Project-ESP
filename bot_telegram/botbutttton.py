from info import *
list_btn = types.InlineKeyboardMarkup()
list_btn2 = types.InlineKeyboardMarkup()
list_btn3 = types.InlineKeyboardMarkup()
b1= types.InlineKeyboardButton(text="yes,iam astra",callback_data="y")
b2= types.InlineKeyboardButton(text="no",callback_data="n")
b4= types.InlineKeyboardButton(text="time",callback_data="time")
b5= types.InlineKeyboardButton(text="astra",callback_data="astra")
b6= types.InlineKeyboardButton(text="EGYPT",callback_data="eg")
b7= types.InlineKeyboardButton(text="UTC",callback_data="utc")
list_btn.add(b1,b2)
list_btn2.add(b4,b5)
list_btn3.add(b6,b7)
def callback_result (call):
    if call.data == "y":
        Astra.send_message(call.message.chat.id, "good for you bro")
    elif call.data == "n":
        Astra.send_message(call.message.chat.id, "bad for you")
    elif call.data == "time":
        Astra.send_message(call.message.chat.id,  "what time want ?", reply_markup=list_btn3)    
    elif call.data == "astra":
        Astra.send_message(call.message.chat.id, "you astra ?", reply_markup=list_btn)    
    elif call.data == "eg":
        Astra.send_message(call.message.chat.id, time_egy)
    elif call.data == "utc":
        Astra.send_message(call.message.chat.id, time_utc)        
        
         #Astra.reply_to(m,"you astra ?", reply_markup=list_btn)