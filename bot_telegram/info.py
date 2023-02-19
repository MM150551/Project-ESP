import datetime as dt
from sqlalchemy import true
import pytz
import telebot
from telebot import types
from telebot import REPLY_MARKUP_TYPES
import time 
from telebot.types import Message
from telebot.types import InlineKeyboardMarkup
from telebot.types import InlineKeyboardButton
from telegram import *
from requests import *

token_bot = "6247412809:AAFlUT3zZL-FEbWExnrFsRtbdgIq42D59XI"
Astra = telebot.TeleBot(token_bot)
