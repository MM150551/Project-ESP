from info import *
from replay import *
from botcommands import *
from botbutttton import *
from telebot import types
@Astra.callback_query_handler(func=lambda call: true )
def myBTN_callback(call):
    callback_result (call)
    
@Astra.message_handler( commands=['start'] )   
def mystartCOMN (m):
    comnd_star_fun(m)
@Astra.message_handler( commands=['ban'] ) 
def mybanCOMN (m):
    comnd_ban_fun(m)
     

     
@Astra.message_handler( func = lambda m: true )
def rm(m):
    replay_fun(m)
         
Astra.infinity_polling()    