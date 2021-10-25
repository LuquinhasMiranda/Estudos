using Godot;
using System;

public class PlayerMovement : KinematicBody
{
    /*
        CAMERA MOVEMENT /////////////////////////////////////////////////////////////
    */
    float MOUSE_SENSITIVITY = .5f;
    const int MOUSE_MAX_Y = 90;
    const int MOUSE_MIN_Y = -90;

    /*
        PLAYER MOVEMENT /////////////////////////////////////////////////////////////
    */
    const int KEY_ESC = 16777217;
    const int KEY_W = 87;
    const int KEY_S = 83;
    const int KEY_D = 68;
    const int KEY_A = 65;
    const int KEY_SPACE = 32;
    bool KEY_SPACE_LAST = false;
    const int KEY_SHIFT = 16777237;
    const int KEY_CTRL = 16777238;

    Vector3 RAW_INPUT;

    // VALORES BASE
    const float BASE_SPEED = 100;
    const float BASE_FALL_SPEED = 30;
    const float MAX_FALL_SPEED = 40;
    const float BASE_JUMP_SPEED = 20;

    // MULTIPLICADORES
    const float WALK_SPEED_MULT = .5f;
    const float RUN_SPEED_MULT = 1.6f;
    const float ON_AIR_MULT = .05f;

    float FINAL_SPEED;
    Vector3 FINAL_INPUT = new Vector3(0, 0, 0);
    Vector3 FINAL_VELOCITY = new Vector3(0, 0, 0);

    public override void _Process(float delta)
    {
        /*
            EXIT PROGRAM 
        */
        if (Input.IsKeyPressed(KEY_ESC)) GetTree().Quit();

        /*
            CAMERA /////////////////////////////////////////////////////////////
        */
        // CALCULO DO MOUSE DELTA
        float MOUSE_X_DELTA = (((GetViewport().GetMousePosition().x) / GetViewport().Size.x) - .5f) * 2;
        float MOUSE_Y_DELTA = (((GetViewport().GetMousePosition().y) / GetViewport().Size.y) - .5f) * 2;

        GetViewport().WarpMouse(new Vector2(GetViewport().Size.x / 2, GetViewport().Size.y / 2));

        GetNode<Spatial>("MeshInstance").RotateObjectLocal(Vector3.Up, -MOUSE_X_DELTA * MOUSE_SENSITIVITY); // GIRA EIXO X
        GetNode<Spatial>("MeshInstance/Camera").RotateObjectLocal(Vector3.Right, -MOUSE_Y_DELTA * MOUSE_SENSITIVITY); // GIRA EIXO Y
        if (GetNode<Spatial>("MeshInstance/Camera").RotationDegrees.x > MOUSE_MAX_Y) GetNode<Spatial>("MeshInstance/Camera").SetRotationDegrees(new Vector3(MOUSE_MAX_Y, GetNode<Spatial>("MeshInstance/Camera").Rotation.y, 0));
        else if (GetNode<Spatial>("MeshInstance/Camera").RotationDegrees.x < MOUSE_MIN_Y) GetNode<Spatial>("MeshInstance/Camera").SetRotationDegrees(new Vector3(MOUSE_MIN_Y, GetNode<Spatial>("MeshInstance/Camera").Rotation.y, 0));

        /*
            PLAYER MOVEMENT //////////////////////////////////////////////////////
        */
        if (Input.IsKeyPressed(KEY_W)) RAW_INPUT.z--;
        if (Input.IsKeyPressed(KEY_S)) RAW_INPUT.z++;
        if (Input.IsKeyPressed(KEY_D)) RAW_INPUT.x++;
        if (Input.IsKeyPressed(KEY_A)) RAW_INPUT.x--;

        RAW_INPUT = RAW_INPUT.Normalized(); // ( AJUSTA VELOCIDADE DIAGONAL )

        if (!IsOnFloor()) // CONTROLE NO AR
        {
            RAW_INPUT.x *= ON_AIR_MULT;
            RAW_INPUT.z *= ON_AIR_MULT;
        }

        bool SPACE_PRESSED = Input.IsKeyPressed(KEY_SPACE);
        if (SPACE_PRESSED != KEY_SPACE_LAST) 
        {
            if (SPACE_PRESSED) RAW_INPUT.y = 1;
            else RAW_INPUT.y = 0;
            KEY_SPACE_LAST = SPACE_PRESSED;
        }

        float CameraAngle = GetNode<Spatial>("MeshInstance").RotationDegrees.y;

        // SPEED FORMULA
        FINAL_SPEED = BASE_SPEED;
        if (Input.IsKeyPressed(KEY_SHIFT)) FINAL_SPEED *= RUN_SPEED_MULT;
        if (Input.IsKeyPressed(KEY_CTRL))  FINAL_SPEED *= WALK_SPEED_MULT;

        // CHECK PULO E ONGROUND
        float INPUT_Y = 0;
        if (IsOnFloor()) INPUT_Y = RAW_INPUT.y * BASE_JUMP_SPEED;

        // ACELERACAO
        float INPUT_X =  (RAW_INPUT.z * Mathf.Sin(CameraAngle / 180 * Mathf.Pi)) + (RAW_INPUT.x * Mathf.Cos(CameraAngle / 180 * Mathf.Pi));
        float INPUT_Z = -(RAW_INPUT.x * Mathf.Sin(CameraAngle / 180 * Mathf.Pi)) + (RAW_INPUT.z * Mathf.Cos(CameraAngle / 180 * Mathf.Pi));
        FINAL_INPUT = new Vector3(INPUT_X,
                                  INPUT_Y,
                                  INPUT_Z);

        FINAL_VELOCITY.x += FINAL_INPUT.x * FINAL_SPEED * delta;
        FINAL_VELOCITY.z += FINAL_INPUT.z * FINAL_SPEED * delta;
        FINAL_VELOCITY.y += FINAL_INPUT.y;

        // DESACELERACAO
        if (IsOnFloor())
        {
            FINAL_VELOCITY.x -= FINAL_VELOCITY.x * 10f * delta;
            FINAL_VELOCITY.z -= FINAL_VELOCITY.z * 10f * delta;
        }

        if (IsOnFloor() & FINAL_VELOCITY.y < 1)
            FINAL_VELOCITY.y = -BASE_FALL_SPEED * delta;
        else
            FINAL_VELOCITY.y -= BASE_FALL_SPEED * delta;
        if (-FINAL_VELOCITY.y >= MAX_FALL_SPEED) FINAL_VELOCITY.y = -MAX_FALL_SPEED; // LIMITE DE VELOCIDADE QUEDA

        // TOUCH CEILING
        if (IsOnCeiling())
            FINAL_VELOCITY.y = 0;

        RAW_INPUT = new Vector3(0, 0, 0);

        MoveAndSlide(FINAL_VELOCITY, Vector3.Up);
    }
}
