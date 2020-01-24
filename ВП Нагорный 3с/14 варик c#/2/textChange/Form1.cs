using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace textChange
{
    public partial class MyClass
    {

    } Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void ChangeButton_Click(object sender, EventArgs e)
        {
            if (textBox.Text == "" || textToChange.Text == "")
                MessageBox.Show("Вы ничего не ввели", "Сообщение");
            else
            {
                var text = textBox.Text.Split('\n');
                string returnValue = "";
                for (var i = 0; i < text.Length; i++)
                {
                    if (text[i].IndexOf(textToChange.Text) == -1)
                    {
                        returnValue += text[i] + "\n";
                    }
                }
                textBox.Text = returnValue;
            }
        }
        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (openFileDialog1.ShowDialog() == DialogResult.Cancel)
                return;
            // получаем выбранный файл
            string filename = openFileDialog1.FileName;
            // читаем файл в строку
            string fileText = System.IO.File.ReadAllText(filename);
            textBox.Text = fileText;
        }

        private void changeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (saveFileDialog1.ShowDialog() == DialogResult.Cancel)
                return;
            // получаем выбранный файл
            string filename = saveFileDialog1.FileName;
            // сохраняем текст в файл
            System.IO.File.WriteAllText(filename, textBox.Text);
        }

        private void clearTextToChange_Click(object sender, EventArgs e)
        {
            textToChange.Text = "";
        }

        private void clearTextBox_Click(object sender, EventArgs e)
        {
            textBox.Text = "";
        }
    }
}
