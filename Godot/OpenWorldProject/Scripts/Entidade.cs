using Godot;
using System;

public class Entidade : Spatial
{
	// VARIAVEIS DE POSICAO E MOVIOMENTO
	Vector3 posicao = new Vector3(0,0,0);
	Vector3 momentum = new Vector3(0,0,0);
	float gravidade = 10;
	float aceleracao = 0;
	float angulo_camera = 0;
	
	public void reset() {
		posicao = new Vector3(0,0,0);
		momentum = new Vector3(0,0,0);
	}
	
	// Called when the node enters the scene tree for the first time.
	public override void _Ready()
	{
		
	}

	// Called every frame. 'delta' is the elapsed time since the previous frame.
	public override void _Process(float delta)
	{
		if (Input.IsKeyPressed('A'))
		{
			GD.Print("A");
		}
	}
}
