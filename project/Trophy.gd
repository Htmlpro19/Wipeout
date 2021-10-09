extends Spatial


# Declare member variables here. Examples:
# var a = 2
# var b = "text"


# Called when the node enters the scene tree for the first time.
func _ready():
	connect("body_entered" , self, "_area_entered") 
	connect("body_exited" , self, "_area_exited")   

func _area_entered(object):   
	print("Collision detected")


# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):
#	pass
