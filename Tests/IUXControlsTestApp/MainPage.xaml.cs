using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;

namespace IUXControlsTestApp;

public sealed partial class MainPage : Page
{
    private bool _isTitleBarAttached;

    public MainPage()
    {
        InitializeComponent();

        Loaded += MainPage_Loaded;
        Unloaded += MainPage_Unloaded;

        AttachTitleBar();
    }

    private void MainPage_Loaded(object sender, RoutedEventArgs e)
    {
        AttachTitleBar();
        WindowingTitleBar.RecomputeDragRegions();
    }

    private void MainPage_Unloaded(object sender, RoutedEventArgs e)
    {
        if (!_isTitleBarAttached)
        {
            return;
        }

        App.Window.SetTitleBar(null);
        _isTitleBarAttached = false;
    }

    private void AttachTitleBar()
    {
        if (_isTitleBarAttached)
        {
            return;
        }

        App.Window.SetTitleBar(WindowingTitleBar);
        _isTitleBarAttached = true;
    }
}
