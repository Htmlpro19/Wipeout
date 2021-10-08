extends MeshInstance


# Declare member variables here. Examples:
# var a = 2
# var b = "text"




# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	rotation += Vector3(0, 5 * delta, 0);
