import javax.swing.*;
import java.awt.*;

public class DrawCircle extends JFrame {
    private int x;
    private int y;
    private int width;
    private int height;
    private int radius;
    public DrawCircle() {
        setTitle("Draw Circle");
        setSize(400, 400);
        setVisible(true);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
    }

    public DrawCircle(int x, int y, int width, int height, int radius) {
        this();
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;
        this.radius = radius;
    }

    @Override
    public void paint(Graphics g) {
        Graphics2D graphics2D = (Graphics2D) g;
        Color orange = Color.orange;
        Color red = Color.red;
        Color green = Color.green;
        drawRect(graphics2D, x, y, width, height, orange);
        drawCircle(graphics2D, x, y, radius, red);
        drawCircle(graphics2D, x, y, radius/2, green);
    }

    private void drawRect(Graphics2D g, int x, int y, int width, int height, Color color) {
        x = x - (width / 2);
        y = y - (height / 2);
        g.setColor(color);
        g.fillRect(x, y, width, height);
    }
    private void drawCircle(Graphics2D g, int x, int y, int radius, Color color) {
        x = x - (radius / 2);
        y = y - (radius / 2);
        g.setColor(color);
        g.fillOval(x, y, radius, radius);
    }

    public static void main(String[] args) {
        int x = 200;
        int y = 200;
        int width = 200;
        int height = 200;
        int radius = 200;
        new DrawCircle(x, y, width, height, radius);
    }
}