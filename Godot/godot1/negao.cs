using Godot;
using System;

public class negao : KinematicBody
{
    const int KEY_W = 87;
    const int KEY_S = 83;
    const int KEY_D = 68;
    const int KEY_A = 65;

    int MOVE_X = 0;
    int MOVE_Z = 0;

    const int HORIZONTAL_SPEED = 20;
    const int HORIZONTAL_SPEED_MOD = 20;

    Vector3 vel = new Vector3();

    // Called when the node enters the scene tree for the first time.
    public override void _Ready() {
        GD.Print("script start");       
    }

    // Called every frame. 'delta' is the elapsed time since the previous frame.
    public override void _Process(float delta) {
        if (Input.IsKeyPressed(KEY_W)) MOVE_Z++;
        if (Input.IsKeyPressed(KEY_S)) MOVE_Z--;
        if (Input.IsKeyPressed(KEY_D)) MOVE_X++;
        if (Input.IsKeyPressed(KEY_A)) MOVE_X--;
        GD.Print(MOVE_Z + "" + MOVE_X);

        vel.x = MOVE_X * delta * HORIZONTAL_SPEED;
        vel.z = MOVE_Z * delta * HORIZONTAL_SPEED;

        vel = vel.Normalized();

        vel = MoveAndSlide(vel, Vector3.Up);

        MOVE_Z = 0;
        MOVE_X = 0;
    }
}
