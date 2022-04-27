/*
** EPITECH PROJECT, 2021
** menu
** File description:
** room music
*/

#include "../includes/music.h"

sounds *create_sounds(void)
{
    sounds *so = malloc(sizeof(sounds));
    so->tr_room = sfSound_create();
    so->p_hurt = sfSound_create();
    so->p_die = sfSound_create();

    sfSoundBuffer *t_room =
    sfSoundBuffer_createFromFile("./sounds/sfx/tr_room.ogg");
    sfSoundBuffer *p_hurt =
    sfSoundBuffer_createFromFile("./sounds/sfx/p_hurt.wav");
    sfSoundBuffer *p_die =
    sfSoundBuffer_createFromFile("./sounds/sfx/p_die.wav");

    sfSound_setBuffer(so->tr_room, t_room);
    sfSound_setBuffer(so->p_hurt, p_hurt);
    sfSound_setBuffer(so->p_die, p_die);
    return so;
}

music *create_music(void)
{
    music *mu = malloc(sizeof(music));
    mu->men = sfMusic_createFromFile("./sounds/title_scr.ogg");
    mu->fl_1_2 = sfMusic_createFromFile("./sounds/cellar.ogg");
    mu->fl_3_4 = sfMusic_createFromFile("./sounds/necropolis.ogg");
    mu->fl_5 = sfMusic_createFromFile("./sounds/dark_room.ogg");
    mu->id_m = 0;
    mu->tmp_id = -1;
    sounds *so = create_sounds();
    return mu;
}

void music_launcher(reduce *red, int floor, int state, music *mu)
{
    int id_music = -1;
    char *music_list[] = {"./sounds/title_scr.ogg", "./sounds/cellar.ogg",
    "./sounds/necropolis.ogg", "./sounds/dark_room.ogg"};
    if (mu->id_m == mu->tmp_id)
        return;
    mu->tmp_id = mu->id_m;

    if (mu->tmp_id != 0)
        sfMusic_destroy(mu->music);

    id_music = (mu->id_m == 0) ? 0 : id_music;
    id_music = (mu->id_m == 1 || mu->id_m == 2) ? 1 : id_music;
    id_music = (mu->id_m == 3 || mu->id_m == 4) ? 2 : id_music;
    id_music = (mu->id_m == 5) ? 3 : id_music;
    mu->music = sfMusic_createFromFile(music_list[id_music]);
    sfMusic_play(mu->music);
    sfMusic_setLoop(mu->music, sfTrue);
}
