import wx
import wx.adv
import webbrowser

TRAY_TOOLTIP = 'Dicks out for harambe'
TRAY_ICON = 'icon.ico'

def create_menu_item(menu, label, func):
    item = wx.MenuItem(menu, -1, label)
    item.SetBitmap(wx.Bitmap(TRAY_ICON))
    menu.Bind(wx.EVT_MENU, func, id=item.GetId())
    menu.Append(item)
    return item

class TaskBarIcon(wx.adv.TaskBarIcon):
    def __init__(self, frame):
        self.frame = frame
        super().__init__()
        self.set_icon(TRAY_ICON)
        self.Bind(wx.adv.EVT_TASKBAR_LEFT_DOWN, self.on_left_down)

    def CreatePopupMenu(self):
        menu = wx.Menu()
        create_menu_item(menu, 'Hide', self.hide_console)
        create_menu_item(menu, 'Hello', self.on_hello)
        menu.AppendSeparator()
        create_menu_item(menu, 'Exit', self.on_exit)
        return menu

    def set_icon(self, path):
        icon = wx.Icon(path)
        self.SetIcon(icon, TRAY_TOOLTIP)

    def hide_console(self, path):
        self.frame.Hide()

    def on_hello(self, event):
        print('Hello comarade, Welcome to mother Russia!')

    def on_left_down(self, event):
        webbrowser.open('http://localhost:9000')

    def on_exit(self, event):
        print('Exiting application')
        wx.CallAfter(self.Destroy)
        self.frame.Close()

class App(wx.App):
    def OnInit(self):
        frame = wx.Frame(None)
        self.SetTopWindow(frame)
        TaskBarIcon(frame)
        return True

def main():
    app = App(False)
    app.MainLoop()

if __name__ == '__main__':
    main()