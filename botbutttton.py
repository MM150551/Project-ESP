from info import *
list_btn = types.InlineKeyboardMarkup()
list_btn2 = types.InlineKeyboardMarkup()
b1= types.InlineKeyboardButton(text="yes,iam astra",callback_data="y")
b2= types.InlineKeyboardButton(text="no",callback_data="n")
b3= types.InlineKeyboardButton(text="/start",callback_data="start")
b4= types.InlineKeyboardButton(text="time",callback_data="time")
b5= types.InlineKeyboardButton(text="astra",callback_data="astra")
list_btn.add(b1,b2)
list_btn2.add(b3,b4,b5)
def callback_result (call):
    if call.data == "y":
        Astra.send_message(call.message.chat.id, "good for you bro")
    
    elif call.data == "n":
        Astra.send_message(call.message.chat.id, "bad for you")