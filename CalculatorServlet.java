
import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.WebServlet;

@WebServlet("/CalculatorServlet")
public class CalculatorServlet extends HttpServlet
{
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException
    {
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        int a = Integer.parseInt(request.getParameter("n1"));
        int b = Integer.parseInt(request.getParameter("n2"));
        String op = request.getParameter("op");
        int result = 0;

        if(op.equals("+"))
            result = a + b;
        else if(op.equals("-"))
            result = a - b;
        else if(op.equals("*"))
            result = a * b;
        else if(op.equals("/"))
            result = a / b;
        else if(op.equals("%"))
            result = a % b;

        out.println("<html><body>");
        out.println("<h2>Result = " + result + "</h2>");
        out.println("<a href='index.html'>Back</a>");
        out.println("</body></html>");
    }
}
5m

Add an Emoji, Sticker, or GIF
