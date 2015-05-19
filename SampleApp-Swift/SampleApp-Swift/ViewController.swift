//
//  ViewController.swift
//  SampleApp-Swift
//
//  Copyright (c) 2014 PayPal. All rights reserved.
//

import UIKit

class ViewController: UIViewController, CardIOPaymentViewControllerDelegate {

  @IBOutlet weak var resultLabel: UILabel!
  override func viewDidLoad() {
    super.viewDidLoad()
    // Do any additional setup after loading the view, typically from a nib.
    CardIOUtilities.preload()
  }

  override func didReceiveMemoryWarning() {
    super.didReceiveMemoryWarning()
    // Dispose of any resources that can be recreated.
  }
  
  @IBAction func scanCard(sender: AnyObject) {
    var cardIOVC = CardIOPaymentViewController(paymentDelegate: self)
    cardIOVC.modalPresentationStyle = .FormSheet
    presentViewController(cardIOVC, animated: true, completion: nil)
  }
  
  func userDidCancelPaymentViewController(paymentViewController: CardIOPaymentViewController!) {
    resultLabel.text = "user canceled"
    paymentViewController?.dismissViewControllerAnimated(true, completion: nil)
  }
  
  func userDidProvideCreditCardInfo(cardInfo: CardIOCreditCardInfo!, inPaymentViewController paymentViewController: CardIOPaymentViewController!) {
    if let info = cardInfo {
      let str = NSString(format: "Received card info.\n Number: %@\n expiry: %02lu/%lu\n cvv: %@.", info.redactedCardNumber, info.expiryMonth, info.expiryYear, info.cvv)
      resultLabel.text = str as String
    }
    paymentViewController?.dismissViewControllerAnimated(true, completion: nil)
  }  
}
