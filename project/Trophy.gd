extends Spatial


# Declare member variables here. Examples:
# var a = 2
# var b = "text"
onready var musicPlayer = get_node("VictorySoundPlayer")
onready var areaNode = get_node("Area")
var start = 0

# Called when the node enters the scene tree for the first time.
func _ready():
	areaNode.connect("body_entered" , self, "_area_entered") 

func _area_entered():   
	print("Collision detected")
	if(start == 1):
		musicPlayer.play()
	start += 1

# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):
#	pass
