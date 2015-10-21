#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mlx.h>
#include "remote.h"

int     main(void)
{
    t_mlx       mlx;

    if ((mlx.mlx = mlx_init()) == NULL)
        return (EXIT_FAILURE);
    if ((mlx.win = mlx_new_window(mlx.mlx, 640, 480, "Hello world")) == NULL)
        return (EXIT_FAILURE);
    if ((mlx.img_bg = mlx_new_image(mlx.mlx, BG_SIZE_X, BG_SIZE_Y)) == NULL)
        return (EXIT_FAILURE);
    draw_bg(&mlx);
    handle_events(&mlx);
    return (EXIT_SUCCESS);
}

int     draw_bg(t_mlx *mlx)
{
    int x = 0;
    int y = 0;

    mlx->img_bg = mlx_xpm_file_to_image(mlx->mlx,
       "background.xpm",
       &x,
       &y);
    return (0);
}

int     handle_events(t_mlx *mlx)
{
    mlx_key_hook(mlx->win, &event_key, mlx);
    mlx_expose_hook(mlx->win, &event_expose, mlx);
    mlx_loop(mlx->mlx);
    return (0);
}

int     event_expose(void *param, int x, int y, int tree_y)
{
    t_mlx       *mlx;

    mlx = (t_mlx *) param;
    mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_bg, 0, 0);
    return (0);
}

int     event_key(int keycode, void *param)
{
    t_mlx       *mlx;

    mlx = (t_mlx *) param;
    printf("%d\n", keycode);
    if (keycode == KEY_ECHAP)
        exit(0);
    return (0);
}