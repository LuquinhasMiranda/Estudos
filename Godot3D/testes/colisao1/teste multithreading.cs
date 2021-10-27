using Godot;
using System;
using System.Threading;

public class colisao : Spatial
{
    int numero = 0;

    public override void _Ready()
    {
        System.Threading.Thread t = new System.Threading.Thread(new System.Threading.ThreadStart(ThreadProc));
        
    }
    
    public override void _PhysicsProcess(float delta)
    {
        GD.Print(numero);
    }
    
    public static void ThreadProc() {
        bool stop = false;
        while (!stop)
        {
            numero++;
        }
    }
}
