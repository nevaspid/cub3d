/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <oliove@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 03:41:26 by oliove            #+#    #+#             */
/*   Updated: 2024/07/04 03:45:13 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


// Fonction fictive pour charger une texture à partir d'un fichier
mlx_texture_t* load_texture(mlx_t *mlx, const char* filename) 
{
    mlx_texture_t* texture = mlx_load_png(filename);
    if (!texture) {
        fprintf(stderr, "Failed to load texture: %s\n", filename);
        exit(1);
    }
    return texture;
}

t_animation load_animation(mlx_t *mlx, const char** filenames, int frame_count, double frame_duration) {
    t_animation anim;
    anim.frames = malloc(frame_count * sizeof(mlx_image_t));
    anim.frame_count = frame_count;
    anim.current_frame = 0;
    anim.frame_duration = frame_duration;
    anim.elapsed_time = 0.0;

    for (int i = 0; i < frame_count; i++) {
        anim.frames[i] = mlx_texture_to_image(mlx,load_texture(mlx, filenames[i]));
    }

    return anim;
}

// Mettre à jour l't_animation en fonction du temps écoulé
void update_animation(t_animation* anim, double delta_time) {
    anim->elapsed_time += delta_time;
    if (anim->elapsed_time >= anim->frame_duration) {
        anim->current_frame = (anim->current_frame + 1) % anim->frame_count;
        anim->elapsed_time = 0.0;
    }
}

// Afficher l't_animation à l'écran
void draw_animation(mlx_t *mlx, mlx_image_t *img, t_animation anim, int x, int y) {
    mlx_image_t *current_img = anim.frames[anim.current_frame];
    mlx_image_to_window(mlx, img, x, y);
    
    // mlx_draw_texture(img, current_img, x, y);
}

int main() {
    // Initialisation de MLX
    mlx_t *mlx = mlx_init(WIDTH, HEIGHT, "t_animation Example", true);
    if (!mlx) {
        fprintf(stderr, "Failed to initialize MLX\n");
        return 1;
    }

    // Créer une image MLX
    mlx_image_t *img = mlx_new_image(mlx, WIDTH, HEIGHT);

    // Exemple de noms de fichiers d'images d't_animation
    const char* filenames[] = {"SAMPLE/DOOR_1A.PNG","SAMPLE/BRICK_6D.PNG" ,"SAMPLE/CONCRETE_4A.PNG"};
    int frame_count = 3;
    double frame_duration = 0.1;  // 100 ms par image

    // Charger l't_animation
    t_animation anim = load_animation(mlx, filenames, frame_count, frame_duration);

    // Boucle principale
    double last_time = mlx_get_time();
    while (!mlx_is_key_down(mlx, MLX_KEY_ESCAPE)) {
        double current_time = mlx_get_time();
        double delta_time = current_time - last_time;
        last_time = current_time;

        // Mettre à jour l't_animation
        update_animation(&anim, delta_time);

        // Effacer l'image et dessiner l't_animation
        mlx_image_to_window(mlx, img, 0, 0);
        draw_animation(mlx, img, anim, 100, 100);

        // Mettre à jour l'affichage
        // mlx_update(mlx);
    }

    // Libérer la mémoire des textures
    // for (int i = 0; i < frame_count; i++) {
    //     mlx_delete_texture(anim.frames[i]);
    // }
    free(anim.frames);
    mlx_delete_image(mlx, img);
    mlx_terminate(mlx);

    return 0;
}
