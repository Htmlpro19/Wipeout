extends Spatial


# Declare member variables here. Examples:
# var a = 2
# var b = "text"
onready var fist1 = get_node("WipeoutFist")
onready var originalPos1 = fist1.translation
onready var dest1 = originalPos1 + Vector3(-1.9, 0, 0)

onready var fist2 = get_node("WipeoutFist2")
onready var originalPos2 = fist2.translation
onready var dest2 = originalPos2 + Vector3(-1.9, 0, 0)

onready var fist3 = get_node("WipeoutFist3")
onready var originalPos3 = fist3.translation
onready var dest3 = originalPos3 + Vector3(-1.9, 0, 0)

onready var fist4 = get_node("WipeoutFist4")
onready var originalPos4 = fist4.translation
onready var dest4 = originalPos4 + Vector3(-1.9, 0, 0)

onready var fist5 = get_node("WipeoutFist5")
onready var originalPos5 = fist5.translation
onready var dest5 = originalPos5 + Vector3(-1.9, 0, 0)

var timeLeft = 1;


# Called when the node enters the scene tree for the first time.
func _ready():
	pass # Replace with function body.


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	timeLeft -= delta
	
	if(timeLeft <= 0):
		fist1.translation = dest1
		fist3.translation = dest3
		fist5.translation = dest5
		
		if(timeLeft <= -1):
			timeLeft = 1
	else:
		fist1.translation = originalPos1
		fist3.translation = originalPos3
		fist5.translation = originalPos5
