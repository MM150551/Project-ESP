from info import *
from replay import *
from botcommands import *
from botbutttton import *

@Astra.message_handler( commands=['start','my_info' ,'ban' ] )
def my_allCOMN (m):
    command_fun(m)
     
@Astra.callback_query_handler(func=lambda call: true )
def myBTN_callback(call):
    callback_result (call)
       
@Astra.message_handler( func = lambda m: true )
def rm(m):
    replay_fun(m)
         
Astra.infinity_polling()    