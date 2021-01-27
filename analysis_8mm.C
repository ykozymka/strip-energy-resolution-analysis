#define test_cxx
#include "r010_0011.h"	//Header file which defines root tree to take events from
#include <TH2.h>
#include <TH1.h>
#include <TF1.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <string>
#include <TPaveStats.h>
#include <TPaveText.h>
#include <TText.h>
#include <TSpectrum.h>
#include <fstream>
#include <TLegend.h>
using namespace std;

void test::Loop()
{
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
	TH1F*gala_E1[100];
	TH1F*gala_E2[100];
	TH1F*gala_E3[100];
	TH1F*gala_E4[100];
	TH1F*gala_E5[100];
	TH1F*gala_E6[100];
	TH1F*gala_E7[100];
	TH1F*gala_E8[100];
	TH1F*gala_E9[100];
	TH1F*gala_E10[100];	//Define histograms

	std::ofstream ofs ("data.txt", std::ofstream::out);	//Define data output file
	ofs << "Strip\tEnergy\tSD_D\tSD_Q\tSD_S\tSD_O\tSD_LB42\tSD_LB62\tSD_LB64\tSD_LB82\tSD_LB84\tSD_LB86\tchisq1\tchisq2\tchisq3\tchisq4\tchisq5\tchisq6\tchisq7\tchisq8\tchisq9\n";

	TCanvas*canv = new TCanvas("mycanvas", "Canvas", 0, 0, 1920, 1080);	//Canvas size
	gStyle->SetOptStat(0);		//Hide stat window
//	canv->Divide(5,4);		//Divide canvas when displaying multiple histograms
	for(unsigned int x = 6; x<7; x++)	//Strip 1 broken, start with x=3 to get coincidence with x=22, x<7 for 4 strips, x<23 for 20 strips; loop over strips
	{
	 gala_E1[x]  = new TH1F("gala_E1" , "LaBr in coincidence with strips",200,4500,9500);
	 gala_E2[x]  = new TH1F("gala_E2" , "LaBr in coincidence with strips",200,4500,9500);
	 gala_E3[x]  = new TH1F("gala_E3" , "LaBr in coincidence with strips",200,4500,9500);
	 gala_E4[x]  = new TH1F("gala_E4" , "LaBr in coincidence with strips",200,4500,9500);
	 gala_E5[x]  = new TH1F("gala_E5" , "LaBr in coincidence with strips",200,4500,9500);
	 gala_E6[x]  = new TH1F("gala_E6" , "LaBr in coincidence with strips",200,4500,9500);
	 gala_E7[x]  = new TH1F("gala_E7" , "LaBr in coincidence with strips",200,4500,9500);
	 gala_E8[x]  = new TH1F("gala_E8" , "LaBr in coincidence with strips",200,4500,9500);
	 gala_E9[x]  = new TH1F("gala_E9" , "LaBr in coincidence with strips",200,4500,9500);
	 gala_E10[x]  = new TH1F("gala_E10" , "LaBr in coincidence with strips",200,4500,9500);	//Create histograms with bin size 25 keV
	   for (Long64_t jentry=0; jentry<nentries;jentry++)
	   {
		Long64_t ientry = LoadTree(jentry);
	      	if (ientry < 0) break;
	      	nb = fChain->GetEntry(jentry);   nbytes += nb;
	    	if (!(*gala_En_cal).empty() && !(*strip_num).empty())	//Take non-empty events
		{
			for(unsigned int i = 0; i<(*gala_En_cal).size(); i++)	//Loop over Galatea energy
			{
				if ((*gala_ch)[i]==10)	//take Galatea channel 10
					{for (unsigned int j=0; j<(*strip_num).size();j++)	//Loop over strips
						{if ((*strip_num)[j]==x && (*gala_tsC)[i]-(*strip_tsC)[j]>=-1.881 && (*gala_tsC)[i]-(*strip_tsC)[j]<=-0.446) 
	                 				{for (unsigned int k=0; k<(*strip_num).size(); k++)	//Loop over strips for coincident event
								{if ((*strip_num)[k]==x-1 && (*gala_tsC)[i]-(*strip_tsC)[k]>=-1.881 && (*gala_tsC)[i]-(*strip_tsC)[k]<=-0.446)
								gala_E1[x]->Fill((*gala_En_cal)[i]);
								if ((*strip_num)[k]==x+1 && (*gala_tsC)[i]-(*strip_tsC)[k]>=-1.881 && (*gala_tsC)[i]-(*strip_tsC)[k]<=-0.446)
								gala_E2[x]->Fill((*gala_En_cal)[i]);
								}	//if k
							}	//for k
						if ((*strip_num)[j]==x+1 && (*gala_tsC)[i]-(*strip_tsC)[j]>=-1.881 && (*gala_tsC)[i]-(*strip_tsC)[j]<=-0.446)
                                                	{for (unsigned int l=0; l<(*strip_num).size(); l++)	//Loop over strips for coincident event
								{if ((*strip_num)[l]==x+2 && (*gala_tsC)[i]-(*strip_tsC)[l]>=-1.881 && (*gala_tsC)[i]-(*strip_tsC)[l]<=-0.446)
								gala_E3[x]->Fill((*gala_En_cal)[i]);
								}	//if l
                                                	}	//for l
						if ((*strip_num)[j]==x+2 && (*gala_tsC)[i]-(*strip_tsC)[j]>=-1.881 && (*gala_tsC)[i]-(*strip_tsC)[j]<=-0.446)
                                                	{for (unsigned int m=0; m<(*strip_num).size(); m++)	//Loop over strips for coincident event
								{if ((*strip_num)[m]==x+3 && (*gala_tsC)[i]-(*strip_tsC)[m]>=-1.881 && (*gala_tsC)[i]-(*strip_tsC)[m]<=-0.446)
								gala_E4[x]->Fill((*gala_En_cal)[i]);
								}	//if m
                                                	}	//for m
                                		}	//if j
	                 		}	//for j
	          		}	//if gala_ch
			}	//for i
		}	//if gala and strip non empty
	canv->cd(x-2);		//Canvas position for assigning histograms, start at cd(1)
	gala_E5[x]->Add(gala_E1[x], 1);
	gala_E5[x]->Add(gala_E2[x], 1);
	gala_E6[x]->Add(gala_E2[x], 1);
	gala_E6[x]->Add(gala_E3[x], 1);
	gala_E7[x]->Add(gala_E3[x], 1);
	gala_E7[x]->Add(gala_E4[x], 1);		//Fill 4 mm histograms E5-E7 with neighbouring 2 mm histograms E1-E4
	gala_E8[x]->Add(gala_E5[x], 1);
	gala_E8[x]->Add(gala_E3[x], 1);
	gala_E9[x]->Add(gala_E6[x], 1);
	gala_E9[x]->Add(gala_E4[x], 1);		//Fill 6 mm histograms E8, E9 with neighbouring4 mm + 2 mm for continuous coverage without doubling
	gala_E10[x]->Add(gala_E5[x], 1);
	gala_E10[x]->Add(gala_E7[x], 1);	//Fill 8 mm histogram E10 with two 4 mm histograms for continuous coverage without doubling
	TSpectrum *s1 = new TSpectrum(2);
	TSpectrum *s2 = new TSpectrum(2);
	TSpectrum *s3 = new TSpectrum(2);
	TSpectrum *s4 = new TSpectrum(2);
	TSpectrum *s5 = new TSpectrum(2);
	TSpectrum *s6 = new TSpectrum(2);
	TSpectrum *s7 = new TSpectrum(2);
	TSpectrum *s8 = new TSpectrum(2);
	TSpectrum *s9 = new TSpectrum(2);
	TSpectrum *s10 = new TSpectrum(2);	//Define spectra for peaks
	Int_t nfound1 = s1->Search(gala_E1[x], 2, "", 0.10);
	Int_t nfound2 = s2->Search(gala_E2[x], 2, "", 0.10);
	Int_t nfound3 = s3->Search(gala_E3[x], 2, "", 0.10);
	Int_t nfound4 = s4->Search(gala_E4[x], 2, "", 0.10);
	Int_t nfound5 = s5->Search(gala_E5[x], 2, "", 0.10);
	Int_t nfound6 = s6->Search(gala_E6[x], 2, "", 0.10);
	Int_t nfound7 = s7->Search(gala_E7[x], 2, "", 0.10);
	Int_t nfound8 = s8->Search(gala_E8[x], 2, "", 0.10);
	Int_t nfound9 = s9->Search(gala_E9[x], 2, "", 0.10);
	Int_t nfound10 = s10->Search(gala_E10[x], 2, "", 0.10);		//Fill spectra with 2 peaks each
	Double_t *peaks1 = s1->GetPositionX();
	Double_t *peaks2 = s2->GetPositionX();
	Double_t *peaks3 = s3->GetPositionX();
	Double_t *peaks4 = s4->GetPositionX();
	Double_t *peaks5 = s5->GetPositionX();
	Double_t *peaks6 = s6->GetPositionX();
	Double_t *peaks7 = s7->GetPositionX();
	Double_t *peaks8 = s8->GetPositionX();
	Double_t *peaks9 = s9->GetPositionX();
	Double_t *peaks10 = s10->GetPositionX();	//Get X position of peaks and put them in array
	Int_t peak11 = 0;
	Int_t peak12 = 0;
	Int_t peak21 = 0;
	Int_t peak22 = 0;
	Int_t peak31 = 0;
	Int_t peak32 = 0;
	Int_t peak41 = 0;
	Int_t peak42 = 0;
	Int_t peak51 = 0;
	Int_t peak52 = 0;
	Int_t peak61 = 0;
	Int_t peak62 = 0;
	Int_t peak71 = 0;
	Int_t peak72 = 0;
	Int_t peak81 = 0;
	Int_t peak82 = 0;
	Int_t peak91 = 0;
	Int_t peak92 = 0;
	Int_t peak01 = 0;
	Int_t peak02 = 0;	//Reset peaks
	if (peaks1[0]<peaks1[1]) {
	peak11 = peaks1[1];
	peak12 = peaks1[0];
	}
	else{
	peak11 = peaks1[0];
	peak12 = peaks1[1];
	}
	if (peaks2[0]<peaks2[1]) {
        peak21 = peaks2[1];
	peak22 = peaks2[0];
        }
        else{
        peak21 = peaks2[0];
	peak22 = peaks2[1];
        }
	if (peaks3[0]<peaks3[1]) {
        peak31 = peaks3[1];
	peak32 = peaks3[0];
        }
        else{
        peak31 = peaks3[0];
	peak32 = peaks3[1];
        }
	if (peaks4[0]<peaks4[1]) {
        peak41 = peaks4[1];
	peak42 = peaks4[0];
        }
        else{
        peak41 = peaks4[0];
	peak42 = peaks4[1];
        }
	if (peaks5[0]<peaks5[1]) {
        peak51 = peaks5[1];
	peak52 = peaks5[0];
        }
        else{
        peak51 = peaks5[0];
	peak52 = peaks5[1];
        }
	if (peaks6[0]<peaks6[1]) {
        peak61 = peaks6[1];
	peak62 = peaks6[0];
        }
        else{
        peak61 = peaks6[0];
	peak62 = peaks6[1];
        }
	if (peaks7[0]<peaks7[1]) {
	peak71 = peaks7[1];
	peak72 = peaks7[0];
	}
	else{
	peak71 = peaks7[0];
	peak72 = peaks7[1];
	}
	if (peaks8[0]<peaks8[1]) {
	peak81 = peaks8[1];
	peak82 = peaks8[0];
	}
	else{
	peak81 = peaks8[0];
	peak82 = peaks8[1];
	}
	if (peaks9[0]<peaks9[1]) {
	peak91 = peaks9[1];
	peak92 = peaks9[0];
	}
	else{
	peak91 = peaks9[0];
	peak92 = peaks9[1];
	}
	if (peaks10[0]<peaks10[1]) {
	peak01 = peaks10[1];
	peak02 = peaks10[0];
	}
	else{
	peak01 = peaks10[0];
	peak02 = peaks10[1];
	}	//Select peak with higher energy and put it in variable peakX1
	TF1 *g11    = new TF1("g11","gaus", peak11-150, peak11+150);
	TF1 *g21    = new TF1("g21","gaus", peak21-150, peak21+150);
	TF1 *g31    = new TF1("g31","gaus", peak31-150, peak31+150);
	TF1 *g41    = new TF1("g41","gaus", peak41-150, peak41+150);
	TF1 *g51    = new TF1("g51","gaus", peak51-150, peak51+150);
	TF1 *g61    = new TF1("g61","gaus", peak61-150, peak61+150);
	TF1 *g71    = new TF1("g71","gaus", peak71-150, peak71+150);
	TF1 *g81    = new TF1("g81","gaus", peak81-175, peak81+175);
	TF1 *g91    = new TF1("g91","gaus", peak91-150, peak91+150);
	TF1 *g01    = new TF1("g01","gaus", peak01-175, peak01+200);	//Define fit Gaussians with range around peak
	g11->SetLineColor(kRed);
	g21->SetLineColor(kGreen);
	g31->SetLineColor(kBlue);
	g41->SetLineColor(kYellow);
	g51->SetLineColor(kViolet);
	g61->SetLineColor(kCyan);
	g71->SetLineColor(kOrange-7);
	g81->SetLineColor(kOrange);
	g91->SetLineColor(kPink);
	g01->SetLineColor(kBlack);
  gala_E1[x]->SetLineColor(kRed+1);
  gala_E2[x]->SetLineColor(kGreen+1);
	gala_E3[x]->SetLineColor(kBlue+1);
	gala_E4[x]->SetLineColor(kYellow+1);
	gala_E5[x]->SetLineColor(kViolet+1);
	gala_E6[x]->SetLineColor(kCyan+1);
	gala_E7[x]->SetLineColor(kOrange+3);
	gala_E8[x]->SetLineColor(kOrange+1);
	gala_E9[x]->SetLineColor(kPink+1);
	gala_E10[x]->SetLineColor(kGray+1);	//Set histogram and fitfunction colours
	gala_E1[x]->Fit(g11,"R+");
	gala_E2[x]->Fit(g21,"R+");
	gala_E3[x]->Fit(g31,"R+");
	gala_E4[x]->Fit(g41,"R+");
	gala_E5[x]->Fit(g51,"R+");
	gala_E6[x]->Fit(g61,"R+");
	gala_E7[x]->Fit(g71,"R+");
	gala_E8[x]->Fit(g81,"R+");
	gala_E9[x]->Fit(g91,"R+");
	gala_E10[x]->Fit(g01,"R+");	//Fit gaussians and set them to draw on canvas
	gala_E10[x]->GetXaxis()->SetTitle("GALATEA energy in keV");
	gala_E10[x]->GetXaxis()->CenterTitle(true);
	gala_E10[x]->GetXaxis()->SetTitleOffset(1.1);
	gala_E10[x]->GetYaxis()->SetTitle("Counts");
	gala_E10[x]->GetYaxis()->CenterTitle(true);
	gala_E10[x]->GetXaxis()->SetTitleOffset(1.1);
	gala_E10[x]->Draw();		//E10 has the highest counts, draw first to set automatically set yrange
	gala_E1[x]->Draw("same");
	gala_E2[x]->Draw("same");
	gala_E3[x]->Draw("same");
	gala_E4[x]->Draw("same");
	gala_E5[x]->Draw("same");
	gala_E6[x]->Draw("same");
	gala_E7[x]->Draw("same");
	gala_E8[x]->Draw("same");
	gala_E9[x]->Draw("same");	//Draw histograms
	auto legend = new TLegend(0.6, 0.7, 0.9, 0.9);
	legend->SetHeader("Spectra of different energy ranges", "C");
	legend->AddEntry(gala_E1[x],"2 mm coverage","l");
	legend->AddEntry(gala_E2[x],"2 mm coverage","l");
	legend->AddEntry(gala_E3[x],"2 mm coverage","l");
	legend->AddEntry(gala_E4[x],"2 mm coverage","l");
	legend->AddEntry(gala_E5[x],"4 mm coverage accumulated","l");
	legend->AddEntry(gala_E8[x],"6 mm coverage accumulated","l");
	legend->AddEntry(gala_E10[x],"8 mm coverage accumulated","l");
	legend->Draw();
	double chisq01=g01->GetChisquare();
	double chisq11=g11->GetChisquare();
	double chisq21=g21->GetChisquare();
	double chisq31=g31->GetChisquare();
	double chisq41=g41->GetChisquare();
	double chisq51=g51->GetChisquare();
	double chisq61=g61->GetChisquare();
	double chisq71=g71->GetChisquare();
	double chisq81=g81->GetChisquare();
	double chisq91=g91->GetChisquare();	//Print chisquare for fit quality determination
	if (x>2)
		  {
		  Float_t sigmaD1=abs(g11->GetParameter("Sigma"));
		  Float_t sigmaD2=abs(g21->GetParameter("Sigma"));
		  Float_t sigmaD3=abs(g31->GetParameter("Sigma"));
		  Float_t sigmaD4=abs(g41->GetParameter("Sigma"));
		  Float_t sigmaQ1=abs(g51->GetParameter("Sigma"));
		  Float_t sigmaQ2=abs(g61->GetParameter("Sigma"));
		  Float_t sigmaQ3=abs(g71->GetParameter("Sigma"));
		  Float_t sigmaS1=abs(g81->GetParameter("Sigma"));
		  Float_t sigmaS2=abs(g91->GetParameter("Sigma"));
		  Float_t sigmaO=abs(g01->GetParameter("Sigma"));		//Get standard deviations from fitfunctions
			Float_t sigmaD=(sigmaD1+sigmaD2+sigmaD3+sigmaD4)/4;
			Float_t sigmaQ=(sigmaQ1+sigmaQ2+sigmaQ3)/3;
			Float_t sigmaS=(sigmaS1+sigmaS2)/2;		//Average standard deviations for identical overlaps to somewhat negate strip efficiency effects
			Float_t sigmaLaBr82=sqrt(16*(sigmaD*sigmaD)/15-sigmaO*sigmaO/15);
			Float_t sigmaLaBr84=sqrt(4*(sigmaQ*sigmaQ)/3-sigmaO*sigmaO/3);
			Float_t sigmaLaBr86=sqrt(16*(sigmaS*sigmaS)/7-9*sigmaO*sigmaO/7);
			Float_t sigmaLaBr62=sqrt(9*(sigmaD*sigmaD)/8-sigmaS*sigmaS/8);
			Float_t sigmaLaBr64=sqrt(9*(sigmaQ*sigmaQ)/5-4*(sigmaS*sigmaS)/5);
			Float_t sigmaLaBr42=sqrt(4*(sigmaD*sigmaD)/3-sigmaQ*sigmaQ/3);		//Calculate LaBr sigma from measured values
			ofs << x;
			ofs << "\t";
			ofs << peak01;
		  ofs << "\t";
      ofs << sigmaD;
      ofs << "\t";
			ofs << sigmaQ;
			ofs << "\t";
			ofs << sigmaS;
			ofs << "\t";
			ofs << sigmaO;
			ofs << "\t";
			ofs << sigmaLaBr42;
      ofs << "\t";
      ofs << sigmaLaBr62;
			ofs << "\t";
			ofs << sigmaLaBr64;
			ofs << "\t";
			ofs << sigmaLaBr82;
			ofs << "\t";
			ofs << sigmaLaBr84;
			ofs << "\t";
			ofs << sigmaLaBr86;
			ofs << "\t";
			ofs << chisq11;
			ofs << "\t";
			ofs << chisq21;
			ofs << "\t";
			ofs << chisq31;
			ofs << "\t";
      ofs << chisq41;
			ofs << "\t";
      ofs << chisq51;
			ofs << "\t";
      ofs << chisq61;
			ofs << "\t";
      ofs << chisq71;
			ofs << "\t";
      ofs << chisq81;
			ofs << "\t";
      ofs << chisq91;
			ofs << "\n";		//Print variables into text file
		}
	}
	ofs.close();		//Close text file
}
