#ifndef REMOTE_H_

# define REMOTE_H_

# define WIN_SIZE_X 800
# define WIN_SIZE_Y 600
# define WIN_NAME "Remote control"
# define BG_SIZE_X 800
# define BG_SIZE_Y 600
# define KEY_ECHAP 53
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define WHITE 0x00FFFFFF
# define GREEN 0x0000C20D
# define BLACK 0x00000000

typedef union   s_color
{
    int         color;
    char        composante[4];
}               t_color;

typedef struct  s_mlx
{
    void        *mlx;
    void        *win;
    void        *img_bg;
}               t_mlx;

int     draw_bg(t_mlx *mlx);
int     handle_events(t_mlx *mlx);
int     event_expose(void *param, int x, int y, int tree_y);
int     event_key(int keycode, void *param);

#endif /* !REMOTE_H_ */
