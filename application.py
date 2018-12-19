from flask import Flask, flash, redirect, render_template, request, session
from helpers import apology

app = Flask(__name__)

app.config['DEBUG'] = True
app.config["TEMPLATES_AUTO_RELOAD"] = True

@app.route("/")
def index():
    """renders the index page, template heavily adapted from https://creatability.withgoogle.com/keyboard/"""
    return render_template("index.html")

@app.route("/mouseplay")
def mouseplay():
    """plays a note using hover action of mouse"""
    return render_template("keyboard_mouse.html")

@app.route("/play")
def play():
    return render_template("keyboard_mouse.html")

@app.route("/random")
def rand():
    return apology("na ho payega!", 400)

@app.route("/keyplay")
def keyplay():
    """plays a note using keys"""
    return render_template("keyboard_keys.html")

@app.route("/espplay")
def espplay():
    """plays a note using espkeys"""
    return render_template("keyboard_esp.html")

@app.route("/about")
def about():
    """display about the work"""
    return render_template("about.html")
