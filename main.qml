import QtQuick 2.9
import QtQml 2.1
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

Window {
    id:mainFrame
    width: 640
    height: 480
    visible: true
    title: qsTr("QuickSort UI")
    //color: "black"
    //testing
    property int _width: sliderSize.value
    //line
    Rectangle{
        id: baseLine
        width: parent.width
        height: 1
        color: "white"
        x: 0
        y: 0
    }
    ScrollView{
        id: scroll
        anchors.fill: parent
        Row{
            spacing: 2
            anchors.top: baseLine.bottom
            width: parent.width
            height: parent.height
            Repeater{
                id:repeater
                //it will assign model later
                //delegate
                delegate: Rectangle{
                    id: newRect
                    height: backEnd.elements[index] //height = at any value from model elements data
                    width: _width
                    color: _rgb(redSlider.value, greenSlider.value, blueSlider.value)
                }//end of Rectangle
            }//end of repeater
        }//end of row
    }//end of ScrollView
    //UI controls
    Button{
        id: generateBtn
        x: 5
        y: parent.height - 45
        text: "Generate Elements"
        onClicked: {
            backEnd.clearElements(); //cleaning array
            //calling C++ backEnd to generate unorder elements
            backEnd.generateElements(textFieldSize.text)
            //assigning data to model
            repeater.model = textFieldSize.text
        }
    }
    TextField{
        id: textFieldSize
        x:140
        y: generateBtn.y
        placeholderText: "Elements size ..."
        onTextChanged: slider.value = textFieldSize.text * 1

    }
    Button{
        id:sortBtn
        x: 345
        y: textFieldSize.y
        text: "Sort Elements"
        onClicked:{
            backEnd.startSorting()//sorting unorder elements
            backEnd.clearElements(); //cleaning array of elements in c++ side
            textFieldSize.text = 0
        }
    }
    //slider
    Slider{
        id: slider
        anchors.left: sortBtn.right
        y: textFieldSize.y
        from: 0
        to: 2000
        value: 20
        stepSize: 1
        opacity: 0.5
        onValueChanged: textFieldSize.text = value
    }
    //slider 2
    Slider{
        id: sliderSize
        anchors.bottom: slider.top
        x: slider.x
        y: textFieldSize.y
        from: 1
        to: 50
        value: 5
        stepSize: 1
        opacity: 0.5
        orientation: "Vertical"
        onValueChanged: _width = value
    }
    //slider colors
    Slider{
    id:redSlider
    width: 200
    x:5
    y:350
    from: 0
    to: 255
    stepSize: 1
    opacity: 0.5
    onValueChanged: redTextSlider.text = value
    }
    //slider
    Slider{
    id:blueSlider
    width: 200
    x:5
    y:300
    from: 0
    to: 255
    stepSize: 1
    opacity: 0.5
    onValueChanged: blueTextSlider.text = value
    }
    //slider
    Slider{
    id:greenSlider
    width: 200
    x:5
    y:250
    from: 0
    to: 255
    stepSize: 1
    opacity: 0.5
    onValueChanged: greenTextSlider.text = value
    }
    //text
    Text {
        id: redTextSlider
        text: "0"
        anchors.left: redSlider.right
        y: redSlider.y
        color: "red"
        font.pixelSize: 18
        opacity: 0.5
    }
    //text
    Text {
        id: blueTextSlider
        text: "0"
        anchors.left: blueSlider.right
        y: blueSlider.y
        color: "blue"
        font.pixelSize: 18
        opacity: 0.5
    }
    //text
    Text {
        id: greenTextSlider
        text: "0"
        anchors.left: greenSlider.right
        y: greenSlider.y
        color: "green"
        font.pixelSize: 18
        opacity: 0.5
    }
    //function
    function _rgb(r, g, b){//return just this color if no effect is made
        if(redSlider.value == 0 && greenSlider.value == 0 && blueSlider.value == 0) return "lightblue"
        //return random rgb color
    return Qt.rgba(r, g, b)
    }
}
