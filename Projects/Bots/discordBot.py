"""
This program is for a new discord bot
Started on 10/21/2022

"""
import hikari
import lightbulb
import datetime
from datetime import date

#below gets today's date
today = date.today()
currDay = today.strftime("%B %d, %Y")


#Below is my bot's token
TOKEN = "MTAzMzIwMDQyNDQxMDQyNzQ2Mg.GSDhlD.df-wnzzNHHxe3X-X4_Mzxoe76Dnt_XGaMmXi2U"

#Below syncs the bot and its token
Test_Server_ID = 516347217918033958
HomieSexual = 717225887795380234
bot = lightbulb.BotApp(token = TOKEN, default_enabled_guilds = (Test_Server_ID, HomieSexual))


#below creates an event
@bot.listen(hikari.GuildMessageCreateEvent) #triggeres when a message is sent
async def message(event): #function header for event
    print(event.content)

"""
COMMANDS
"""

#below creates a slash command to say hello
@bot.command
@lightbulb.command('hello', 'says introduction')
@lightbulb.implements(lightbulb.SlashCommand)
async def hello(ctx): #function header
    await ctx.respond("Hello from your school idol You Watanabe!")


#The command below displays information about the bot
@bot.command
@lightbulb.command('info', 'displays information')
@lightbulb.implements(lightbulb.SlashCommand)
async def info(ctx):
    await ctx.respond("My name is You Watanabe. I am a 2nd generation school idol!" + '\n' + 
                      "I'm managed by alfonso")


#The command below displays today's date
@bot.command
@lightbulb.command('today', "displays todays date")
@lightbulb.implements(lightbulb.SlashCommand)
async def today(ctx):
    await ctx.respond("Today's date is " + currDay)


#The command below will be used to check in for November
@bot.command
@lightbulb.command('nut-in', "check's in for today")
@lightbulb.implements(lightbulb.SlashCommand)
async def nutin(ctx):
    await ctx.respond("You have checked in for " + currDay)



#below runs the bot
bot.run()